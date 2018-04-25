// -*- C++ -*-
/*!
 * @file Pressure.cpp
 * @brief Controls Pressure.
 * @date $Date: $
 *
 * $Id: $
 *
 */
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>

#include <unistd.h>


#include <Pressure.h>


namespace WEIApp
{
  #define PRESSURE_ADDRESS 0x60
  #define PRESSURE_OSS 0 

  /*!
   * @brief Constructor
   * @param none
   */
  Pressure::Pressure()
  {
    m_i2cFilename = "/dev/i2c-1";
    m_pressureAddress = PRESSURE_ADDRESS;
    m_a0 = 0.0;
    m_b1 = 0.0;
    m_b2 = 0.0;
    m_c12 = 0.0;
  }
  /*!
   * @brief Destructor
   * @param none
   */
  Pressure::~Pressure(void)
  {
  }
  /*!
   * @brief Pressure initialization
   * @return true: Success
   *         false:Failure
   */
  bool Pressure::initPressure()
  {
    m_pressure = ::open(m_i2cFilename.c_str(), O_RDWR);
    if(m_pressure < 0)
      {
        std::cout<<"Faild to open i2c port"<<std::endl;
        return false;
      }
    if (ioctl(m_pressure, I2C_SLAVE, m_pressureAddress) < 0)
      {
        std::cout<<"Unable to get bus access to talk to slave"<<std::endl;
        return false;
      }
    ::usleep(100000);

    char buf[256];

    //Reading coefficient data
    buf[0] = 0x04;//command
    ::write(m_pressure, buf, 1);
    ::usleep(5000);

    unsigned char coefficientData[8];
    for(int ic=0;ic<8;++ic)
      {
        ::read(m_pressure, &coefficientData[ic], 1);
        ::usleep(5000);
      }

    {
    std::cout<<"coefficientData"<<std::endl;
    std::stringstream ss;
    for(int ic=0;ic<8;++ic)
      {
        ss << std::hex << (int)coefficientData[ic] <<" ";
      }
    std::cout<<ss.str()<<std::endl;
    }

    unsigned short tempData;
    tempData = ((unsigned short)(coefficientData[0]) << 8) + coefficientData[1];
    {
    std::cout<<std::hex<<"tmpDt = "<< tempData <<std::endl;
    std:: cout << resetiosflags(std::ios_base::basefield);
    }
    //double a0(0.0);
    {
    //a0 Signed, Integer Bits = 12, Fractional Bits = 3 :
    //ex)
    //0x3ece = 2009.75
    //0x3ece = 0b0011111011001110
    //Integer part
    //0b0011111011001110 => 0b0011111011001 = 0x7d9 = 2009
    //Fractional part
    //0b0011111011001110 => 0b110 = 1/2 + 1/4 + 0/8 = 0.75
    //tempData = 0x3ece;
    unsigned short signedBit = tempData;
    if(signedBit&0x8000)
      {
        tempData = ~tempData + 1;
      }  
    double ret(0.0);  
    double integer = (tempData & 0x7ff8) >> 3;

    double fractional(0.0);
    unsigned short temp = tempData << 13;
    for(int ic=0;ic<3;++ic)
      {
        if(temp&0x8000)
          {
            fractional = fractional + std::pow((double)0.5,(ic+1));
          }

        temp = temp << 1;
      }
    ret = integer + fractional;
    if(signedBit&0x8000)
      {
        ret = ret * (-1.0);
      }  
    m_a0 = ret;
    std::cout<<"a0 = "<< m_a0 <<std::endl;
    std:: cout << resetiosflags(std::ios_base::floatfield);
    }
    tempData = ((unsigned short)(coefficientData[2]) << 8) + coefficientData[3];
    {
    std::cout<<std::hex<<"tmpDt = "<< tempData <<std::endl;
    std:: cout << resetiosflags(std::ios_base::basefield);
    }
    //double b1(0.0);
    {
    //b1 Signed, Integer Bits = 2, Fractional Bits = 13 :
    //ex)
    //0xb3f9 = -2.37585
    //0xb3f9 = 0b1011001111111001 => 0b0100110000000111
    //Integer part
    //0b0100110000000111 =>  0b10 = 0x02 = 2
    //Fractional part
    //0b0100110000000111 => 0b0110000000111 = 1/4 + 1/8 + 1/2048 + 1/4096
    //                                      +  1/8192
    //tempData = 0xb3f9;
    unsigned short signedBit = tempData;
    if(signedBit&0x8000)
      {
        tempData = ~tempData + 1;
      }  
    double ret(0.0);  
    double integer = (tempData & 0x6000) >> 13;

    double fractional(0.0);
    unsigned short temp = tempData << 3;
    for(int ic=0;ic<13;++ic)
      {
        if(temp&0x8000)
          {
            fractional = fractional + std::pow((double)0.5,(ic+1));
          }

        temp = temp << 1;
      }
    ret = integer + fractional;
    if(signedBit&0x8000)
      {
        ret = ret * (-1.0);
      }  
    m_b1 = ret;
    std::cout<<"b1 = "<< m_b1 <<std::endl;
    std:: cout << resetiosflags(std::ios_base::floatfield);

    }
    tempData = ((unsigned short)(coefficientData[4]) << 8) + coefficientData[5];
    {
    std::cout<<std::hex<<"tmpDt = "<< tempData <<std::endl;
    std:: cout << resetiosflags(std::ios_base::basefield);
    }
    //double b2(0.0);
    {
    //b2 Signed, Integer Bits = 1, Fractional Bits = 14 :
    //ex)
    //0xc517 = -0.92047
    //0xc517 = 0b1100010100010111  => 0b0011101011101001
    //Integer part
    //0b00111010111010010 => 0b0 = 0x00 = 0 
    //Fractional part
    //0b00111010111010010 => 0b111010111010010 = 1/2 + 1/4 + 1/8 + 1/32 + 1/128
    //                                 + 1/256 + 1/512 + 1/2048  +1/16384
    //                                 = 0.92047119140625
    //tempData = 0xc517;
    unsigned short signedBit = tempData;
    if(signedBit&0x8000)
      {
        tempData = ~tempData + 1;
      }  
    double ret(0.0);  
    double integer = (tempData & 0x4000) >> 14;

    double fractional(0.0);
    unsigned short temp = tempData << 2;
    for(int ic=0;ic<14;++ic)
      {
        if(temp&0x8000)
          {
            fractional = fractional + std::pow((double)0.5,(ic+1));
          }

        temp = temp << 1;
      }
    ret = integer + fractional;
    if(signedBit&0x8000)
      {
        ret = ret * (-1.0);
      }  
    m_b2 = ret;
    std::cout<<"b2 = "<< m_b2 <<std::endl;
    std:: cout << resetiosflags(std::ios_base::floatfield);

    }

    tempData = ((unsigned short)(coefficientData[6]) << 8) + coefficientData[7];
    {
    std::cout<<std::hex<<"tmpDt = "<< tempData <<std::endl;
    std:: cout << resetiosflags(std::ios_base::basefield);
    }
    //double c12(0.0);
    {
    //c12 Signed, Integer Bits = 0, Fractional Bits = 13,  dec pt zero pad = 9 : 
    //ex)
    //0x33c8 = 0.000790
    //0x33c8 = 0b0011001111001000
    //Fractional part
    //0b0011001111001000 => 0b011001111001000 = 1/2^11 + 1/2^12 + 1/2^15 
    //                                 + 1/2^16 + 1/2^17 + 1/2^18 + 1/2^21
    //                                 = 0.00079011917114257812
    //tempData = 0x33c8;
    unsigned short signedBit = tempData;
    if(signedBit&0x8000)
      {
        tempData = ~tempData + 1;
      }  
    double ret(0.0);  
    double integer = 0;

    double fractional(0.0);
    unsigned short temp = tempData << 1;
    for(int ic=0;ic<13;++ic)
      {
        if(temp&0x8000)
          {
            fractional = fractional + std::pow((double)0.5,(ic+10));
          }

        temp = temp << 1;
      }
    ret = integer + fractional;
    if(signedBit&0x8000)
      {
        ret = ret * (-1.0);
      }  
    m_c12 = ret;
    std::cout<<"c12 = "<< m_c12 <<std::endl;
    std:: cout << resetiosflags(std::ios_base::floatfield);

    }

    return true;

  }
  /*!
   * @brief Shutdown Pressure
   * 
   */
  void Pressure::shutdownPressure()
  {
  }


  /*!
   * @brief Gets the Pressure
   * @param none
   * @return press. in Pa
   * 
   */
  double Pressure::getValue()
  {
    char buf[256];

    //Command to I2C Start Conversion
    buf[0] = 0x12;
    buf[1] = 0x00;
    ::write(m_pressure, buf, 2);
    ::usleep(15000);

    buf[0] = 0x00;//command
    ::write(m_pressure, buf, 1);
    ::usleep(5000);

    unsigned char adcCounts[4];
    for(int ic=0;ic<4;++ic)
      {
        ::read(m_pressure, &adcCounts[ic], 1);
        ::usleep(5000);
      }

    std::cout<<"adcCounts"<<std::endl;
    std::stringstream ss;
    for(int ic=0;ic<4;++ic)
      {
        ss << std::hex << (int)adcCounts[ic] <<" ";
      }
    std::cout<<ss.str()<<std::endl;
    unsigned short tempData;
    tempData = ((unsigned short)(adcCounts[0]) << 8) + adcCounts[1];
    double padc;
    {
    //Padc Unsigned, Integer Bits = 10 :
    //ex)
    //0x6680 = 410
    //0x6680 = 0b011001101000000
    //Integer part
    //0b0110011010000000 => 0b0110011010 = 0x19a = 410
    //tempData = 0x6680;
    unsigned short integer = (tempData & 0xffc0) >> 6;

    padc = (double)integer;
    std::cout<<"padc = "<< padc <<std::endl;
    std:: cout << resetiosflags(std::ios_base::floatfield);

    }
    tempData = ((unsigned short)(adcCounts[2]) << 8) + adcCounts[3];
    double tadc;
    {
    //Tadc Unsigned, Integer Bits =10 : 
    //ex)
    //0x7ec0 = 507
    //0x7ec0 = 0b0111111011000000
    //Integer part
    //0b0111111011000000 => 0b0111111011 = 0x1fb =507 
    //tempData = 0x7ec0;
    unsigned short integer = (tempData & 0xffc0) >> 6;

    tadc = (double)integer;
    std::cout<<"tadc = "<< tadc <<std::endl;
    std:: cout << resetiosflags(std::ios_base::floatfield);

    }
    double pcomp = m_a0 + (m_b1 + m_c12 * tadc) * padc + m_b2 * tadc; 
    std::cout<<"pcomp = "<< pcomp <<std::endl;
    double pressure = pcomp * ((1150.0-500.0)/1023.0) + 500.0;
    std::cout<<"pressure = "<< pressure <<std::endl;

    return pressure;

    
   
  }




}; // namespace 

