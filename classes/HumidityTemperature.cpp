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
#include <string.h>

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
    //m_humidityTemperatureAddress = ACCELEROMETER_ADDRESS;
    m_humidityTemperatureAddress = getI2cAddress("40");
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
    if(m_humidityTemperatureAddress == 0)
      {
        std::cout<<" Humidity i2c address error"<<std::endl;
        return false;
      }
    if((m_humidityTemperatureAddress == 0x40) ||
       (m_humidityTemperatureAddress == 0x44) ||
       (m_humidityTemperatureAddress == 0x45)) 
      {
      }
    else
      {
        std::cout<<" Humidity i2c address error"<<std::endl;
        return false;
      }

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


    if(m_humidityTemperatureAddress == 0x40)
      {
        buf[0] = 0x02;
        buf[1] = 0x10;
        buf[2] = 0x00;
        ::write(m_humidityTemperature, buf, 3);
      }
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
    if(m_humidityTemperatureAddress == 0x40)
      {
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
    else
      {
        buf[0] = 0x2C;
        buf[1] = 0x06;
        ::write(m_humidityTemperature, buf, 2);
        ::usleep(20000);

        ::read(m_humidityTemperature, buf, 6);
        //size_t len = ::read(m_humidityTemperature, buf, 6);

        short temperature_val = (((short)buf[0x00]<<8)|((short)buf[0x01]));
        unsigned short humidity_val = (((short)buf[0x03]<<8)|((short)buf[0x04]));


        std::stringstream ss;
        double temperature = ((double)temperature_val*175.0/65536.0)-45.0;
        double humidity = ((double)humidity_val*100.0/65536.0);

        ss << temperature << "," << humidity;
        //ss <<std::fixed<<std::setprecision(2)<< humidity << "% " ;

        //std::cout << hum_ss.str() << std::flush;
        return ss.str();
      }
    

  }
  int HumidityTemperature::getI2cAddress(std::string str)
  {
    std::stringstream ss;
    ss <<"sudo i2cdetect -y 1 | grep " <<str<<": | sed -e \"s/"<<str<<": //g\" | sed -e \"s/-- //g\" | sed -e \"s/ //g\"";
    FILE *fp;
    fp = ::popen(ss.str().c_str(),"r");
    //std::cout<<ss.str()<<std::endl;
    if (fp == NULL) 
      {
        return 0;
      }
    char i2c_buf[64];
    fgets(i2c_buf, sizeof(i2c_buf), fp);
    int len = ::strlen(i2c_buf);
    if(len<2)
      {
        return 0;
      }
    i2c_buf[2] = '\0';
    pclose(fp);
    int addr = std::stoi(i2c_buf, nullptr, 16);
    return addr;
  }



}
