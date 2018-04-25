#include <string>

#include <iostream>
#include <iomanip>
#include <sstream>

#include <unistd.h>

#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <math.h>

int main(int argc, char* argv[])
{
    int illumination;
    illumination = ::open("/dev/i2c-1", O_RDWR);
    if(illumination < 0)
      {
        std::cout<<"Faild to open i2c port"<<std::endl;
        return false;
      }
    if (ioctl(illumination, I2C_SLAVE, 0x39) < 0)
      {
        std::cout<<"Unable to get bus access to talk to slave"<<std::endl;
        return false;
      }
    ::usleep(100000);

    char buf[256];

    //enable the device
    buf[0] = 0x80;
    buf[1] = 0x03;
    ::write(illumination, buf, 2);

    ::usleep(400000);

    buf[0] = 0xac;
    ::write(illumination, buf, 1);
    ::read(illumination, buf, 2);

    unsigned short val;

    std::cout << std::setw(2) << std::setfill('0') << std::hex << (int)buf[0x01] << " " << std::setw(2) << std::setfill('0') << std::hex << (int)buf[0x00] << std::endl;


    buf[0] = 0xae;
    ::write(illumination, buf, 1);
    ::read(illumination, buf, 2);
    
    //std::cout << std::setw(2) << std::setfill('0') << std::hex << (int)buf[0x01] << " " << (int)buf[0x00] << std::endl;

    ::close(illumination);
}
