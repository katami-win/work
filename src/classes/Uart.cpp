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
    new_term_io.c_cc[VMIN] = 1;
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
    //char buf[256];
    //buf[0] = '\0';
    //int res;
    int rp = 0;
    int step = 0;
    for(;;)
      {
        //res = read(m_uart, (char *)&cbuf, 1);
        read(m_uart, (char *)&cbuf, 1);
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
              }
            break;
          }
        if(step == 2)
          {
            break;
          }
      }
    ubuf[rp] = '\0';
    ret = std::string(ubuf);
    std::vector<std::string> vstr;
    std::stringstream u_ss(ret);
    std::string buffer;
    while( std::getline(u_ss, buffer, ',') ) 
      {
        vstr.push_back(buffer);
      }
    std::stringstream ss;
    double lat = 0.0;
    double lon = 0.0;
    if(vstr[0].compare("$GPGGA")==0)
      {
        lat = std::stod(vstr[2]);
        lon = std::stod(vstr[4]);
        lat = lat /100.0;
        lon = lon /100.0;
        //std::cout<<" "<<vstr[0]<<" "<<lat<<"N "<<lon<<"E "<<std::flush;
        //ss<<vstr[0]<<","<<lat<<"N,"<<lon<<"E "<<std::flush;
        ss<<lat<<"N,"<<lon<<"E "<<std::flush;
        //std::cout<<" "<<vstr[2]<<"N "<<vstr[4]<<"E "<<std::flush;
      }
    else if(vstr[0].compare("$GPRMC")==0)
      {
        lat = std::stod(vstr[3]);
        lon = std::stod(vstr[5]);
        lat = lat /100.0;
        lon = lon /100.0;
        //std::cout<<" "<<vstr[0]<<" "<<lat<<"N "<<lon<<"E "<<std::flush;
        //ss<<vstr[0]<<","<<lat<<"N,"<<lon<<"E "<<std::flush;
        ss<<lat<<"N,"<<lon<<"E"<<std::flush;
      }
    else
      {
        //std::cout<<" "<<std::flush;
        return "";
      }
    //std::cout<<ss.str()<<std::endl;
    ret = ss.str();
    return ret;

  }


}; // namespace 

