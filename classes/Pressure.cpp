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
#include <string.h>

#include <unistd.h>


#include "Pressure.h"


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
    //m_pressureAddress = PRESSURE_ADDRESS;
    m_pressureAddress = getI2cAddress("60");
    if(m_pressureAddress == 0)
      {
        m_pressureAddress = getI2cAddress("70");
      }
    m_a0 = 0.0;
    m_b1 = 0.0;
    m_b2 = 0.0;
    m_c12 = 0.0;

    dig_T1 = 0;
    dig_T2 = 0;
    dig_T3 = 0;
    dig_P1 = 0;
    dig_P2 = 0;
    dig_P3 = 0;
    dig_P4 = 0;
    dig_P5 = 0;
    dig_P6 = 0;
    dig_P7 = 0;
    dig_P8 = 0;
    dig_P9 = 0;
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
    if(m_pressureAddress == 0)
      {
        std::cout<<" Pressure i2c address error"<<std::endl;
        return false;
      }
    if((m_pressureAddress == 0x60) ||
       (m_pressureAddress == 0x76) ||
       (m_pressureAddress == 0x77)) 
      {
      }
    else
      {
        std::cout<<" Pressure i2c address error"<<std::endl;
        return false;
      }

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

    if(m_pressureAddress == 0x60)
      {
        //
        //MPL115A2
        //
        
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


      }
    else
      {
        //
        //BMP280
        //

        //ctrl_meas_reg
        buf[0] = 0xf4;
        buf[1] = 0x27;
        ::write(m_pressure, buf, 2);

        //config_reg
        buf[0] = 0xf5;
        buf[1] = 0xb0;
        ::write(m_pressure, buf, 2);

        //read calibration data for temperature
        buf[0] = 0x88;
        ::write(m_pressure, buf, 1);
        ::read(m_pressure, buf, 2);
        dig_T1 = (((short)buf[1]<<8)|((short)buf[0]));
        
        buf[0] = 0x8a;
        ::write(m_pressure, buf, 1);
        ::read(m_pressure, buf, 2);
        dig_T2 = (((short)buf[1]<<8)|((short)buf[0]));
    
        buf[0] = 0x8c;
        ::write(m_pressure, buf, 1);
        ::read(m_pressure, buf, 2);
        dig_T3 = (((short)buf[1]<<8)|((short)buf[0]));
    
        //read calibration data for pressure
        buf[0] = 0x8e;
        ::write(m_pressure, buf, 1);
        ::read(m_pressure, buf, 2);
        dig_P1 = (((short)buf[1]<<8)|((short)buf[0]));
    
        buf[0] = 0x90;
        ::write(m_pressure, buf, 1);
        ::read(m_pressure, buf, 2);
        dig_P2 = (((short)buf[1]<<8)|((short)buf[0]));
      
        buf[0] = 0x92;
        ::write(m_pressure, buf, 1);
        ::read(m_pressure, buf, 2);
        dig_P3 = (((short)buf[1]<<8)|((short)buf[0]));
        
        buf[0] = 0x94;
        ::write(m_pressure, buf, 1);
        ::read(m_pressure, buf, 2);
        dig_P4 = (((short)buf[1]<<8)|((short)buf[0]));
    
        buf[0] = 0x96;
        ::write(m_pressure, buf, 1);
        ::read(m_pressure, buf, 2);
        dig_P5 = (((short)buf[1]<<8)|((short)buf[0]));
    
        buf[0] = 0x98;
        ::write(m_pressure, buf, 1);
        ::read(m_pressure, buf, 2);
        dig_P6 = (((short)buf[1]<<8)|((short)buf[0]));
    
        buf[0] = 0x9a;
        ::write(m_pressure, buf, 1);
        ::read(m_pressure, buf, 2);
        dig_P7 = (((short)buf[1]<<8)|((short)buf[0]));
    
        buf[0] = 0x9c;
        ::write(m_pressure, buf, 1);
        ::read(m_pressure, buf, 2);
        dig_P8 = (((short)buf[1]<<8)|((short)buf[0]));
    
        buf[0] = 0x9e;
        ::write(m_pressure, buf, 1);
        ::read(m_pressure, buf, 2);
        dig_P9 = (((short)buf[1]<<8)|((short)buf[0]));

        /*
        std::cout << "P1 " <<  dig_P1 << std::endl;
        std::cout << "P2 " <<  dig_P2 << std::endl;
        std::cout << "P3 " <<  dig_P3 << std::endl;
        std::cout << "P4 " <<  dig_P4 << std::endl;
        std::cout << "P5 " <<  dig_P5 << std::endl;
        std::cout << "P6 " <<  dig_P6 << std::endl;
        std::cout << "P7 " <<  dig_P7 << std::endl;
        std::cout << "P8 " <<  dig_P8 << std::endl;
        std::cout << "P9 " <<  dig_P9 << std::endl;
        */
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

    if(m_pressureAddress == 0x60)
      {
        //
        //MPL115A2
        //

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

        //std::cout<<"adcCounts"<<std::endl;
        //std::stringstream ss;
        //for(int ic=0;ic<4;++ic)
        //  {
        //    ss << std::hex << (int)adcCounts[ic] <<" ";
        //  }
        //std::cout<<ss.str()<<std::endl;
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
        //std::cout<<"padc = "<< padc <<std::endl;
        //std:: cout << resetiosflags(std::ios_base::floatfield);

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
        //std::cout<<"tadc = "<< tadc <<std::endl;
        //std:: cout << resetiosflags(std::ios_base::floatfield);

        }
        double pcomp = m_a0 + (m_b1 + m_c12 * tadc) * padc + m_b2 * tadc; 
        //std::cout<<"pcomp = "<< pcomp <<std::endl;
        double pressure = pcomp * ((1150.0-500.0)/1023.0) + 500.0;
        //std::cout<<"pressure = "<< pressure <<std::endl;

        return pressure;
      }
    else
      {
        //
        //BMP280
        //

        //read data registers for temperature
        buf[0] = 0xfa;
        ::write(m_pressure, buf, 1);
        ::read(m_pressure, buf, 3);
        long temp_raw = ((long)(buf[0]<<12)&0xff000)|((long)(buf[1]<<4)&0x0ff0)|((long)(buf[2]>>4)&0x0f);

        //read data registers for pressure
        buf[0] = 0xf7;
        ::write(m_pressure, buf, 1);
        ::read(m_pressure, buf, 3);
        long pres_raw = ((long)(buf[0]<<12)&0xff000)|((long)(buf[1]<<4)&0x0ff0)|((long)(buf[2]>>4)&0x0f);
        /*
        {   
            std::ios::fmtflags flagsSaved = std::cout.flags(); 
            std::cout << std::hex << pres_raw << std::endl;
            std::cout.flags(flagsSaved);
        }
        */
        //compensate
        double t_fine = 0.0;
        double var1;
        double var2;
    
        //compensate temperature (for t_fine)
        var1 = (((double)temp_raw)/16384.0 - ((double)dig_T1)/1024.0) * ((double)dig_T2);
        var2 = ((((double)temp_raw)/131072.0 - ((double)dig_T1)/8192.0) * (((double)temp_raw)/131072.0 - ((double) dig_T1)/8192.0)) * ((double)dig_T3);
        t_fine = (var1 + var2);
        /*
        {
            std::ios::fmtflags flagsSaved = std::cout.flags(); 
            std::cout << "t_fine "  << std::defaultfloat << t_fine << std::endl;
            std::cout.flags(flagsSaved);
        }
        */
        //compensate pressuer
        var1 = (t_fine/2.0) - 64000.0;
        var2 = var1 * var1 * ((double)dig_P6) / 32768.0;
        var2 = var2 + var1 * ((double)dig_P5) * 2.0;
        var2 = (var2/4.0)+(((double)dig_P4) * 65536.0);
        var1 = (((double)dig_P3) * var1 * var1 / 524288.0 + ((double)dig_P2) * var1) / 524288.0;
        var1 = (1.0 + var1 / 32768.0)*((double)dig_P1);
        /*
        std::cout << "var1 " << var1 << std::endl;
        std::cout << "var2 " << var2 << std::endl;
        */
        double pressure = 0.0;
        if (var1 != 0.0)
          {
            //std::cout << "pres_raw " << pres_raw << std::endl;
            pressure = 1048576.0 - (double)pres_raw;
            pressure = (pressure - (var2 / 4096.0)) * 6250.0 / var1;
            var1 = ((double)dig_P9) * pressure * pressure / 2147483648.0;
            var2 = pressure * ((double)dig_P8) / 32768.0;
            pressure = pressure + (var1 + var2 + ((double)dig_P7)) / 16.0;
            pressure = pressure/100.0;
          }
        /*
        {
            std::ios::fmtflags flagsSaved = std::cout.flags(); 
            std::cout << std::defaultfloat << pressure << std::endl;
            std::cout.flags(flagsSaved);
        }
        */
        return pressure;
      }

    
   
  }

  int Pressure::getI2cAddress(std::string str)
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




}; // namespace 

