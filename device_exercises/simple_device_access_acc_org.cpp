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
    int m_accelerometer;
    //m_accelerometer = ::open("/dev/i2c-1", O_RDWR);
    m_accelerometer = ::open("/dev/i2c-1", O_RDWR);
    if(m_accelerometer < 0)
      {
        std::cout<<"Faild to open i2c port"<<std::endl;
        return false;
      }
    if (ioctl(m_accelerometer, I2C_SLAVE, 0x1d) < 0)
      {
        std::cout<<"Unable to get bus access to talk to slave"<<std::endl;
        return false;
      }
    ::usleep(100000);

    char buf[256];

    //POWER_CTL
    //buf[0] = 0x2d;buf[1] = 0x08;
    buf[0] = 0x2d;
    buf[1] = 0x08;
    ::write(m_accelerometer, buf, 2);

    //DATA_FORMAT
    //buf[0] = 0x31;buf[1] = 0x0b;
    buf[0] = 0x31;
    buf[1] = 0x0b;
    ::write(m_accelerometer, buf, 2);

    buf[0] = 0x32;
    ::write(m_accelerometer, buf, 1);
    ::read(m_accelerometer, buf, 6);
    
    short x_val = (((short)buf[1]<<8)|((short)buf[0]));
    short y_val = (((short)buf[3]<<8)|((short)buf[2]));
    short z_val = (((short)buf[5]<<8)|((short)buf[4]));

    std::stringstream ss;
    ss << (double)x_val*0.0039 << "," << (double)y_val*0.0039 << "," << (double)z_val*0.0039;

    std::cout << ss.str() << std::endl;

    ::close(m_accelerometer);
}
