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
    m_i2cFilename = "/dev/ttyAMA0";
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
    char buf[256];
    buf[0] = '\0';
    //int res;
    int rp = 0;
    for(;;)
      {
        //res = read(m_uart, (char *)&cbuf, 1);
        read(m_uart, (char *)&cbuf, 1);
        if(cbuf == '$')
          {
            buf[0] = cbuf;
            rp = 1;
          }
        //else if(cbuf == '\r' || cbuf == '\n')
        else if(cbuf == '\n')
          {
            if(
                buf[1] == 'G' &&
                buf[2] == 'P' &&
                buf[3] == 'G' &&
                buf[4] == 'G' &&
                buf[5] == 'A'
            )
              {
                break;
              }
          }
        else
          {
            buf[rp] = cbuf;
            rp++;
            //if(cbuf == '*')
            //  {
            //    break;
            //  }
          }
      }
    buf[rp] = '\0';
    ret = std::string(buf);
    return ret;

  }


}; // namespace 

