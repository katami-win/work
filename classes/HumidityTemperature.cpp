// -*- C++ -*-
/*!
 * @file HumidityTemperature.cpp
 * @brief Controls HumidityTemperature.
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

#include "HumidityTemperature.h"

namespace WEIApp
{
  #define ACCELEROMETER_ADDRESS 0x40
  #define ACCELEROMETER_OSS 0 

  /*!
   * @brief Constructor
   * @param none
   */
  HumidityTemperature::HumidityTemperature()
  {
    m_i2cFilename = "/dev/i2c-1";
    m_humidityTemperatureAddress = ACCELEROMETER_ADDRESS;
  }
  /*!
   * @brief Destructor
   * @param none
   */
  HumidityTemperature::~HumidityTemperature(void)
  {
  }
  /*!
   * @brief HumidityTemperature initialization
   * @return true: Success
   *         false:Failure
   */
  bool HumidityTemperature::initHumidityTemperature()
  {
    m_humidityTemperature = ::open(m_i2cFilename.c_str(), O_RDWR);
    if(m_humidityTemperature < 0)
      {
        std::cout<<"Faild to open i2c port"<<std::endl;
        return false;
      }
    if (ioctl(m_humidityTemperature, I2C_SLAVE, m_humidityTemperatureAddress) < 0)
      {
        std::cout<<"Unable to get bus access to talk to slave"<<std::endl;
        return false;
      }
    ::usleep(100000);


    //config
    char buf[256];


    buf[0] = 0x02;
    buf[1] = 0x10;
    buf[2] = 0x00;
    ::write(m_humidityTemperature, buf, 3);

    return true;

  }
  /*!
   * @brief Shutdown HumidityTemperature
   * 
   */
  void HumidityTemperature::shutdownHumidityTemperature()
  {
  }
  /*!
   * @brief Gets the HumidityTemperature
   * @param none
   * @return 
   * 
   */
  std::string HumidityTemperature::getValue()
  {
    unsigned char buf[256];

    buf[0] = 0x00;
    ::write(m_humidityTemperature, buf, 1);
    ::usleep(20000);

    ::read(m_humidityTemperature, buf, 4);
    //size_t len = ::read(m_humidityTemperature, buf, 4);
    //std::cout << len << std::endl;
    //std::cout << std::setw(2) << std::setfill('0') << std::hex << (int)buf[0x00] << " " << (int)buf[0x01] << " " << (int)buf[0x02] << " " <<(int)buf[0x03] <<  std::endl;
    

    short temperature_val = (((short)buf[0x00]<<8)|((short)buf[0x01]));
    unsigned short humidity_val = (((short)buf[0x02]<<8)|((short)buf[0x03]));

    
    //std::cout << temperature_val << "," << humidity_val << std::endl;
    //std::cout << (temperature_val>>2) << "," << (humidity_val>>2) << std::endl;

    std::stringstream ss;
    double temperature = ((double)temperature_val*165.0/65536.0)-40.0;
    double humidity = ((double)humidity_val*100.0/65536.0);
    ss << temperature << "," << humidity;

    //std::cout << ss.str() << std::endl;

    return ss.str();
    

  }


}
