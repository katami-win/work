// -*- C++ -*-
/*!
 * @file Illumination.cpp
 * @brief Controls Illumination.
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
#include <math.h>

#include "Illumination.h"

namespace WEIApp
{
  #define ILLUMINATION_ADDRESS 0x39
  #define ILLUMINATION_OSS 0 

  /*!
   * @brief Constructor
   * @param none
   */
  Illumination::Illumination()
  {
    m_i2cFilename = "/dev/i2c-1";
    //m_i2cFilename = //To specify the device file
    m_illuminationAddress = ILLUMINATION_ADDRESS;
    //m_illuminationAddress = // Specifies the slave address.
  }
  /*!
   * @brief Destructor
   * @param none
   */
  Illumination::~Illumination(void)
  {
  }
  /*!
   * @brief Illumination initialization
   * @return true: Success
   *         false:Failure
   */
  bool Illumination::initIllumination()
  {
    m_gain = 0;
    m_illumination = ::open(m_i2cFilename.c_str(), O_RDWR);
    if(m_illumination < 0)
      {
        std::cout<<"Faild to open i2c port"<<std::endl;
        return false;
      }
    if (ioctl(m_illumination, I2C_SLAVE, m_illuminationAddress) < 0)
      {
        std::cout<<"Unable to get bus access to talk to slave"<<std::endl;
        return false;
      }
    ::usleep(100000);

    char buf[256];

    //enable the device
    buf[0] = 0x80; buf[1] = 0x03;
    //buf[0] = Set ControlRegister
    //buf[1] = Set PowerUp 
    ::write(m_illumination, buf, 2);

    ::usleep(400000);
    return true;

  }
  /*!
   * @brief Shutdown Illumination
   * 
   */
  void Illumination::shutdownIllumination()
  {
  }
  /*!
   * @brief Sets the Gain
   * @param none
   * @return 
   * 
   */
  void Illumination::setGain(int gain)
  {
    if(gain == 1)
      {
        char buf[256];

        buf[0] = 0x81;
        buf[1] = 0x02;
        ::write(m_illumination, buf, 2);
      }
    else
      {
        char buf[256];

        buf[0] = 0x81;
        buf[1] = 0x12;
        ::write(m_illumination, buf, 2);
      }
    m_gain = gain;
    usleep(800000);
  }
  /*!
   * @brief get the full spectrum
   * @param none
   * @return full spectrum
   * 
   */
  unsigned short Illumination::getFullSpectrum()
  {
    char buf[256];

    buf[0] = 0xac;
    //buf[0] = set ADCChannel0DataRegisters
    ::write(m_illumination, buf, 1);
    ::read(m_illumination, buf, 2);
    
    //std::cout << std::setw(2) << std::setfill('0') << std::hex << (int)buf[0x01] << " " << (int)buf[0x00] << std::endl;
    unsigned short ret_val = (((short)buf[0x01]<<8)|((short)buf[0x00]));

    return ret_val;
        
  }
  /*!
   * @brief get the infrared
   * @param none
   * @return infrared
   * 
   */
  unsigned short Illumination::getInfrared()
  {
    char buf[256];

    buf[0] = 0xae;
    //buf[0] = set ADCChannel1DataRegisters
    ::write(m_illumination, buf, 1);
    ::read(m_illumination, buf, 2);
    
    //std::cout << std::setw(2) << std::setfill('0') << std::hex << (int)buf[0x01] << " " << (int)buf[0x00] << std::endl;
    unsigned short ret_val = (((short)buf[0x01]<<8)|((short)buf[0x00]));

    return ret_val;
        
  }
  /*!
   * @brief Gets the lux
   * @param none 
   * @return 
   * 
   */
  std::string Illumination::getValue()
  {
    unsigned short full = getFullSpectrum();
    unsigned short ir = getInfrared();

    if(m_gain==16)
      {
        if((full==65536)||(ir==65536)) 
          {
            setGain(1);
            full = getFullSpectrum();
            ir = getInfrared();
          }
      }
    
    if(m_gain==1)
      {
        full *= 16;
        ir *= 16;
      }

    double ratio;
    if(full==0)
      {
        ratio = 9999.0;
      }
    else
      {
        ratio = ((double)ir/(double)full);
      }

    //std::cout<<std::dec<<"ir="<<ir<<" full="<<full<<std::endl;

    double lux;
    if((ratio>=0.0) && (ratio<=0.52))
      {
        lux = (0.0315*(double)full) - (0.0593*(double)full*pow(ratio,1.4));
      }
    else if(ratio<=0.65)
      {
        lux = (0.0229*(double)full) - (0.0291*(double)ir);
      }
    else if(ratio<=0.80)
      {
        lux = (0.0157*(double)full) - (0.018*(double)ir);
      }
    else if(ratio<=1.3)
      {
        lux = (0.00338*(double)full) - (0.0026*(double)ir);
      }
    else
      {
        lux = 0;
      }


    std::stringstream ss;
    ss << (double)lux;

    //std::cout << ss.str() << std::endl;

    return ss.str();
    

  }


}
