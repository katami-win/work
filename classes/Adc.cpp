// -*- C++ -*-
/*!
 * @file Adc.cpp
 * @brief Controls Adc.
 * @date $Date: $
 *
 * $Id: $
 *
 */
#include <string>
#include <iostream>
#include <iomanip>

#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>



#include <Adc.h>


namespace WEIApp
{

  /*!
   * @brief Constructor
   * @param none
   */
  Adc::Adc()
  {
    m_spiFilename = "/dev/spidev0.0";
    m_bits = 8;
    m_speed = 500000;
  }
  /*!
   * @brief Destructor
   * @param none
   */
  Adc::~Adc(void)
  {
  }
  /*!
   * @brief Adc initialization
   * @return true: Success
   *         false:Failure
   */
  bool Adc::initAdc()
  {
    int ret=0;
    m_adc = ::open(m_spiFilename.c_str(), O_RDWR);
    if(m_adc < 0)
      {
        std::cout<<"can't open device"<<std::endl;
        return false;
      }
    if (ioctl(m_adc, SPI_IOC_WR_MODE, &m_mode) < 0)
      {
        std::cout<<"can't set spi mode"<<std::endl;
        return false;
      }
    if (ioctl(m_adc, SPI_IOC_RD_MODE, &m_mode) < 0)
      {
        std::cout<<"can't get spi mode"<<std::endl;
        return false;
      }

    ret = ioctl(m_adc, SPI_IOC_WR_BITS_PER_WORD);
    //if (ioctl(m_adc, SPI_IOC_WR_BITS_PER_WORD) < 0)
    if (ret  < 0)
      {
        std::cout<<"can't set bits per word"<<std::endl;
        std::cout<<"ret = "<<ret<<std::endl;
        return false;
      }
    if (ioctl(m_adc, SPI_IOC_RD_BITS_PER_WORD) < 0)
      {
        std::cout<<"can't get bits per word"<<std::endl;
        return false;
      }

    if (ioctl(m_adc, SPI_IOC_WR_MAX_SPEED_HZ, &m_speed) < 0)
      {
        std::cout<<"can't set max speed Hz"<<std::endl;
        return false;
      }
    if (ioctl(m_adc, SPI_IOC_RD_MAX_SPEED_HZ, &m_speed) < 0)
      {
        std::cout<<"can't get max speed Hz"<<std::endl;
        return false;
      }


    return true;

  }
  /*!
   * @brief Shutdown Adc
   * 
   */
  void Adc::shutdownAdc()
  {
  }


  /*!
   * @brief Gets the Adc
   * @param none
   * @return AD value
   * 
   */
  unsigned long Adc::getValue(int channel)
  {
    unsigned long ret;
    struct spi_ioc_transfer tr;
    unsigned char send_chi[] = {0x00,0x08,0x10,0x18};
    unsigned char rx[8];
    unsigned char tx[8];
    rx[0] = 0;
    rx[1] = 0;
    rx[2] = 0;
    rx[3] = 0;
    rx[4] = 0;
    rx[5] = 0;
    rx[6] = 0;
    rx[7] = 0;
    tx[0] = send_chi[channel];
    tx[1] = 0;
    tx[2] = 0;
    tx[3] = 0;
    tx[4] = 0;
    tx[5] = 0;
    tx[6] = 0;
    tx[7] = 0;
  

    tr.tx_buf = (unsigned long)tx;
    tr.rx_buf = (unsigned long)rx;
    tr.len = 4;
    tr.delay_usecs = 0;
    tr.speed_hz = m_speed;
    tr.bits_per_word = m_bits;
    tr.cs_change = 0;

    ret = ioctl(m_adc,SPI_IOC_MESSAGE(1),&tr);
    if(ret == -1)
      {
        std::cout<<"getValue error"<<std::endl;
      }
    //for(int ic=0;ic<4;++ic)
    //  {
    //    std::cout<<std::hex<<std::setw(2)<<std::setfill('0')<<(int)rx[ic]<<" ";
    //  }
    //std::cout<<std::endl;
    ret = ((rx[2] << 6 ) & 0x300) |  ((rx[2] << 6) & 0xc0) | ((rx[3] >> 2) & 0x3f);
    return ret;
  }

  /*!
   * @brief Gets the Adc
   * @param none
   * @return AD value
   * 
   */
  /*
  std::string Adc::getValue(int channel)
  {
    unsigned long val = getValue(channel);
    
    std::stringstream ss;
    ss << val; 

    return ss.str();


  }
 */

  /*!
   * @brief Gets Moisture
   * @param none
   * @return percent
   * 
   */
  int Adc::getMoisture()
  {
    unsigned long val = getValue(0);
    int ret = val*100*5/1023;
    return ret;
  }

  /*!
   * @brief Gets luminosit 
   * @param none
   * @return  lux
   * 
   */
  float Adc::getLuminosity()
  {
    unsigned long val = getValue(1);
    float sensorvalue  = float(val)*5.0/1023.0;
    float ret;
    if(sensorvalue<=1.6)
      {
        ret = (sensorvalue * 1000) /2;
      }
    else if(sensorvalue<=1.8)
      {
        ret = sensorvalue * 1000 - 800;
      }
    else if(sensorvalue<=2.0)
      {
        ret = sensorvalue * 5000 - 8000;
      }
    else
      {
        ret = sensorvalue * 26667 - 51333;
      }
    //std::cout<<sensorvalue<<std::endl;
    //std::cout<<ret<<std::endl;
    return ret;
  }
    
   




}; // namespace 

