// -*- C++ -*-
/*!
 * @file Accelerometer.cpp
 * @brief Controls Accelerometer.
 * @date $Date: $
 *
 * $Id: $
 *
 */

#include <iostream>
#include <iomanip>
#include <sstream>

#include <unistd.h>

#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>

#include "Accelerometer.h"

namespace WEIApp
{
  #define ACCELEROMETER_ADDRESS 0x1d
  #define ACCELEROMETER_OSS 0 

  /*!
   * @brief Constructor
   * @param none
   */
  Accelerometer::Accelerometer()
  {
    m_i2cFilename = "/dev/i2c-1";
    m_accelerometerAddress = ACCELEROMETER_ADDRESS;
  }
  /*!
   * @brief Destructor
   * @param none
   */
  Accelerometer::~Accelerometer(void)
  {
  }
  /*!
   * @brief Accelerometer initialization
   * @return true: Success
   *         false:Failure
   */
  bool Accelerometer::initAccelerometer()
  {
    m_accelerometer = ::open(m_i2cFilename.c_str(), O_RDWR);
    if(m_accelerometer < 0)
      {
        std::cout<<"Faild to open i2c port"<<std::endl;
        return false;
      }
    if (ioctl(m_accelerometer, I2C_SLAVE, m_accelerometerAddress) < 0)
      {
        std::cout<<"Unable to get bus access to talk to slave"<<std::endl;
        return false;
      }
    ::usleep(100000);

    char buf[256];


    buf[0] = 0x2d;
    buf[1] = 0x08;
    ::write(m_accelerometer, buf, 2);

    buf[0] = 0x31;
    buf[1] = 0x0b;
    ::write(m_accelerometer, buf, 2);

    buf[0] = 0x00;
    ::write(m_accelerometer, buf, 1);
    ::read(m_accelerometer, buf, 64);

    //std::cout << "The Device Addr is: " << std::setw(2) << std::setfill('0') << std::hex << m_accelerometerAddress << std::endl;
    //std::cout << "The Device ID is: " << std::setw(2) << std::setfill('0') << std::hex << (int)buf[0] << std::endl;
    //std::cout << "The POWER_CTL mode is: " << std::setw(2) << std::setfill('0') << std::hex << (int)buf[0x2d] << std::endl;
    //std::cout << "The DATA_FORMAT is: " << std::setw(2) << std::setfill('0') << std::hex << (int)buf[0x31] << std::endl;
    //std::cout << std::dec << std::endl;   //reset back to decimal

    return true;

  }
  /*!
   * @brief Shutdown Accelerometer
   * 
   */
  void Accelerometer::shutdownAccelerometer()
  {
  }
  /*!
   * @brief Gets the Accelerometer
   * @param none
   * @return 
   * 
   */
  std::string Accelerometer::getValue()
  {
    unsigned char buf[256];

    buf[0] = 0x32;
    ::write(m_accelerometer, buf, 1);
    ::read(m_accelerometer, buf, 6);

    short x_val = (((short)buf[1]<<8)|((short)buf[0]));
    short y_val = (((short)buf[3]<<8)|((short)buf[2]));
    short z_val = (((short)buf[5]<<8)|((short)buf[4]));

    //std::cout << std::setw(4) << std::setfill('0') << std::hex << x_val << std::endl;
    
    //std::cout << x_val << "," << y_val << "," << z_val <<std::endl;

    std::stringstream ss;
    ss << (double)x_val*0.0039 << "," << (double)y_val*0.0039 << "," << (double)z_val*0.0039;

    //std::cout << ss.str() << std::endl;

    return ss.str();
    

  }

}
