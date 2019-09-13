// -*- C++ -*-
/*!
 * @file Uart.cpp
 * @brief Controls UART
 * @date $Date: $
 *
 * $Id: $
 *
 */
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "Uart.h"


namespace WEIApp
{

  /*!
   * @brief Constructor
   * @param none
   */
  Uart::Uart()
  {
    //m_i2cFilename = "/dev/ttyAMA0";
    m_i2cFilename = "/dev/ttyS0";
    m_status = 0;
    m_is_indicating = false;
    m_indicatingCount = 60;
    m_count = 0;
  }
  /*!
   * @brief Destructor
   * @param none
   */
  Uart::~Uart(void)
  {
  }
  /*!
   * @brief Uart initialization
   * @return true: Success
   *         false:Failure
   */
  bool Uart::initUart()
  {
    m_uart = ::open(m_i2cFilename.c_str(), O_RDWR | O_NOCTTY);
    if(m_uart < 0)
      {
        std::cout<<"Faild to open UART"<<std::endl;
        return false;
      }
    struct termios new_term_io;
    ::tcgetattr(m_uart, &old_term_io);
    new_term_io.c_iflag = 0;
    new_term_io.c_oflag = 0;
    new_term_io.c_cflag = 0;
    new_term_io.c_lflag = 0;
    new_term_io.c_line = 0;
    ::memset(new_term_io.c_cc, '\0', sizeof(new_term_io.c_cc));

    //new_term_io.c_cflag = B19200 | CS8 | CLOCAL | CREAD;
    new_term_io.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
    new_term_io.c_iflag = IGNPAR;
    new_term_io.c_oflag = 0;
    new_term_io.c_lflag = 0;
    new_term_io.c_cc[VTIME] = 0;
    //new_term_io.c_cc[VMIN] = 1;
    new_term_io.c_cc[VMIN] = 0;
    ::tcflush(m_uart, TCIFLUSH);
    ::tcsetattr(m_uart, TCSANOW, &new_term_io);

    m_status = 1;
    return true;

  }
  /*!
   * @brief Shutdown Uart
   * 
   */
  void Uart::shutdownUart()
  {
    ::tcsetattr(m_uart, TCSANOW, &old_term_io);
    ::close(m_uart);
  }

  std::string Uart::readGPGGA()
  {
    //$GPGGA,hhmmss.ss,llll.ll,a,yyyyy.yy,a,x,xx,x.x,x.x,M,x.x,M,x.x,xxxx*hh
    //$GPGGA,085120.307,3541.1493,N,13945.3994,E,1,08,1.0,6.9,M,35.9,M,,0000*5E
    std::string ret;
    char cbuf;
    char ubuf[256];
    char sumbuf[8];
    //char buf[256];
    //buf[0] = '\0';
    //int res;
    int rp = 0;
    int bp = 0;
    int step = 0;
    char sum = 0;
    for(;;)
      {
        //res = read(m_uart, (char *)&cbuf, 1);
        //read(m_uart, (char *)&cbuf, 1);
        size_t len = read(m_uart, (char *)&cbuf, 1);
        if(len == 0)
          {
            ubuf[0] = 'N';
            ubuf[1] = 'C';
            ubuf[2] = '\0';
            rp = 2;
            break;
          }
        switch(step)
          {
          case 0:
            if(cbuf == '$')
              {
                ubuf[0] = cbuf;
                rp = 1;
                step = 1;
              }
            break;
          case 1:
            ubuf[rp] = cbuf;
            rp++;
            if(cbuf == '\n')
              {
                step = 2;
                rp--;
                rp--;
              }
            else if(cbuf == '\r')
              {
                ;
              }
            else if(cbuf == '*')
              {
                step = 2;
                ;
              }
            else
              {
                sum = sum ^ cbuf;
              }
            if(rp == 255) 
              {
                step = 2;
              }
            break;
          case 2:
            if(cbuf == '\n')
              {
                step = 3;
              }
            else if(cbuf == '\r')
              {
                ;
              }
            else
              {
                sumbuf[bp] = cbuf;
                sumbuf[bp+1] = '\0';
                bp++;
                if(bp == 7) 
                  {
                    step = 3;
                  }
              }
            break;
          }
        if(step == 3)
          {
            break;
          }
      }
    ubuf[rp] = '\0';
    ret = std::string(ubuf);
    std::string sumstring = std::string(sumbuf);
    std::vector<std::string> vstr;
    std::stringstream u_ss(ret);
    std::stringstream sum_ss(sumstring);
    std::string buffer;
    std::ostringstream o_ss;
    o_ss <<std::hex<<std::setw(2)<<std::setfill('0')<<std::uppercase<<(int)sum;
    if(sum_ss.str().compare(o_ss.str()) == 0)
      {
        //std::cout<<"sum OK:"<<o_ss.str()<<std::endl;
      }
    else
      {
        std::cout<<"sum error:" <<sum_ss.str()<<"  "<<o_ss.str()<<std::endl;
        std::cout<<ret<<std::endl;
        return "NC";
      }
    while( std::getline(u_ss, buffer, ',') ) 
      {
        vstr.push_back(buffer);
      }
    std::stringstream ss;
    double lat = 0.0;
    double lon = 0.0;
    if(vstr[0].compare("$GPGGA")==0)
      {
        if(vstr.size()>4)
          {
            if((vstr[2].length() != 0) && (vstr[4].length() !=0))
              {
                try
                  {
                    lat = std::stod(vstr[2]);
                    lon = std::stod(vstr[4]);
                    lat = lat /100.0;
                    lon = lon /100.0;
                    ss<<vstr[0]<<" "<<lat<<"N,"<<lon<<"E "<<std::flush;
                  }
                catch(...)
                  {
                    std::cout<<"db:"<<u_ss.str()<<std::endl;
                    ss<<vstr[0]<<std::flush;
                    std::cout<<"  :"<<ss.str()<<std::endl;
                  }
              }
            else
              {
                ss<<vstr[0]<<std::flush;
              }
          }
        else
          { 
            ss<<vstr[0]<<std::flush;
            std::cout<<vstr[0]<<"//"<<std::endl;
          }
      }
    else if(vstr[0].compare("$GPRMC")==0)
      {
        if(vstr.size()>5)
          {
            if((vstr[3].length() != 0) && (vstr[5].length() != 0))
              {
                try
                  {
                    lat = std::stod(vstr[3]);
                    lon = std::stod(vstr[5]);
                    lat = lat /100.0;
                    lon = lon /100.0;
                    ss<<vstr[0]<<" "<<lat<<"N,"<<lon<<"E"<<std::flush;
                  }
                catch(...)
                  {
                    std::cout<<"db:"<<u_ss.str()<<std::endl;
                    ss<<vstr[0]<<std::flush;
                    std::cout<<"  :"<<ss.str()<<std::endl;
                  }
              }
            else
              {
                //ss<<lat<<"N,"<<lon<<"E"<<std::flush;
                ss<<vstr[0]<<std::flush;
              }
          }
        else
          { 
            ss<<vstr[0]<<std::flush;
            std::cout<<vstr[0]<<"//"<<std::endl;
          }
      }
    else
      {
        ss<<vstr[0]<<std::flush;
        //std::cout<<" "<<std::flush;
        //return "";
      }
    //std::cout<<ss.str()<<std::endl;
    ret = ss.str();
    return ret;

  }


}; // namespace 

