#include <string>
#include <iostream>
#include <iomanip>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include <string>
#include <termios.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    //int m_uart = ::open("/dev/ttyS0", O_RDWR | O_NOCTTY);
    int m_uart = ::open(set device name, O_RDWR | O_NOCTTY);
    if(m_uart < 0)
      {
        std::cout<<"Faild to open UART"<<std::endl;
        return false;
      }
    struct termios old_term_io;
    struct termios new_term_io;
    ::tcgetattr(m_uart, &old_term_io);
    new_term_io.c_iflag = 0;
    new_term_io.c_oflag = 0;
    new_term_io.c_cflag = 0;
    new_term_io.c_lflag = 0;
    new_term_io.c_line = 0;
    ::memset(new_term_io.c_cc, '\0', sizeof(new_term_io.c_cc));

    new_term_io.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
    new_term_io.c_iflag = IGNPAR;
    new_term_io.c_oflag = 0;
    new_term_io.c_lflag = 0;
    new_term_io.c_cc[VTIME] = 0;
    new_term_io.c_cc[VMIN] = 1;
    ::tcflush(m_uart, TCIFLUSH);
    ::tcsetattr(m_uart, TCSANOW, &new_term_io);

    std::string ret;
    char cbuf;
    char buf[256];
    buf[0] = '\0';
    int rp = 0;
    int step = 0;
    for(;;)
      {
        //read(m_uart, (char *)&cbuf, 1);
        read(set handle, (char *)&cbuf, 1);
        switch(step)
          {
          case 0:
            if(cbuf == '$')
              {
                buf[0] = cbuf;
                rp = 1;
                step = 1;
              }
	    break;
          case 1:
            buf[rp] = cbuf;
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

    buf[rp] = '\0';
    ret = std::string(buf);
    std::cout<<ret<<std::endl;

    ::tcsetattr(m_uart, TCSANOW, &old_term_io);
    //::close(m_uart);
    ::close(set handle);
}
