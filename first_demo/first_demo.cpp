#include <string>
#include <vector>

#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <regex>

#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>
#include <dirent.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>  // popen, pclose

int g_sig;

void handler(int sig)
{
    g_sig = 1;
}
 
int getI2cAddress(std::string str)
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

int main(int argc, char* argv[])
{
    g_sig = 0;
    ::signal(SIGINT,handler);
    
    std::cout<<"* i2c"<<std::endl;
    int acc_addr = getI2cAddress("10");
    if(acc_addr == 0)
      {
        std::cout<<" Accelerometer i2c address error"<<std::endl;
        return false;
      }
    std::cout<<" Accelerometer:"<<std::hex<<std::setw(2)<<std::setfill('0')<<acc_addr<<std::endl;
    int ill_addr = getI2cAddress("30");
    if(ill_addr == 0)
      {
        std::cout<<" illumination i2c address error"<<std::endl;
        return false;
      }
    std::cout<<" illumination :"<<std::hex<<std::setw(2)<<std::setfill('0')<<ill_addr<<std::endl;
    int hum_addr = getI2cAddress("40");
    if(hum_addr == 0)
      {
        std::cout<<" Humidity i2c address error"<<std::endl;
        return false;
      }
    if((hum_addr == 0x40) ||
       (hum_addr == 0x44) ||
       (hum_addr == 0x45)) 
      {
      }
    else
      {
        std::cout<<" Humidity i2c address error"<<std::endl;
        return false;
      }
    std::cout<<" Humidity     :"<<std::hex<<std::setw(2)<<std::setfill('0')<<hum_addr<<std::endl;
    int pre_addr = getI2cAddress("60");
    if(pre_addr == 0)
      {
        pre_addr = getI2cAddress("70");
        if(pre_addr == 0)
          {
            std::cout<<" Pressure i2c address error"<<std::endl;
            return false;
          }
      }
    std::cout<<" Pressure     :"<<std::hex<<std::setw(2)<<std::setfill('0')<<pre_addr<<std::endl;


    std::cout<<"* 1-wire"<<std::endl;
    std::cout<<" "<<std::flush;
    ::system("ls /sys/bus/w1/devices/ | grep \"28\"");
    std::cout<<"* uart"<<std::endl;
    std::cout<<" "<<std::flush;
    ::system("ls /dev/ttyS0");
    std::cout<<""<<std::endl;
    //
    //Accelerometer initialization
    // 
    std::cout<<"-Accelerometer initialization"<<std::endl;
    int accelerometer;
    accelerometer = ::open("/dev/i2c-1", O_RDWR);
    if(accelerometer < 0)
      {
        std::cout<<"  Faild to open i2c port"<<std::endl;
        ::close(accelerometer);
        return false;
      }
    if (ioctl(accelerometer, I2C_SLAVE, 0x1d) < 0)
      {
        std::cout<<"  Unable to get bus access to talk to slave"<<std::endl;
        std::cout<<"  I2C_SLAVE is 0x1d."<<std::endl;
        ::system("sudo i2cdetect -y 1");
        ::close(accelerometer);
        return false;
      }
    ::usleep(100000);

    char acc_buf[64];

    acc_buf[0] = 0x2d;
    acc_buf[1] = 0x08;
    ::write(accelerometer, acc_buf, 2);

    acc_buf[0] = 0x31;
    acc_buf[1] = 0x0b;
    ::write(accelerometer, acc_buf, 2);

    acc_buf[0] = 0x00;
    ::write(accelerometer, acc_buf, 1);
    ::read(accelerometer, acc_buf, 64);
    
    //
    //Illumination initialization
    //
    std::cout<<"-Illumination initialization"<<std::endl;
    int illumination;
    illumination = ::open("/dev/i2c-1", O_RDWR);
    if(illumination < 0)
      {
        std::cout<<"  Faild to open i2c port"<<std::endl;
        ::close(illumination);
        ::close(accelerometer);
        return false;
      }
    if (ioctl(illumination, I2C_SLAVE, 0x39) < 0)
      {
        std::cout<<"  Unable to get bus access to talk to slave"<<std::endl;
        std::cout<<"  I2C_SLAVE is 0x39."<<std::endl;
        ::system("sudo i2cdetect -y 1");
        ::close(illumination);
        ::close(accelerometer);
        return false;
      }
    ::usleep(100000);

    char ill_buf[8];

    //enable the device
    ill_buf[0] = 0x80;
    ill_buf[1] = 0x03;
    ::write(illumination, ill_buf, 2);

    ::usleep(400000);
    
    //
    // HumidityTemperature initialization
    //
    std::cout<<"-HumidityTemperature initialization"<<std::endl;
    int humidityTemperature;
    humidityTemperature = ::open("/dev/i2c-1", O_RDWR);
    if(humidityTemperature < 0)
      {
        std::cout<<"  Faild to open i2c port"<<std::endl;
        ::close(illumination);
        ::close(accelerometer);
        ::close(humidityTemperature);
        return false;
      }
    if (ioctl(humidityTemperature, I2C_SLAVE, hum_addr) < 0)
      {
        std::cout<<"  Unable to get bus access to talk to slave"<<std::endl;
        std::cout<<"  I2C_SLAVE is "<<std::hex<<hum_addr<<" ."<<std::endl;
        ::system("sudo i2cdetect -y 1");
        ::close(illumination);
        ::close(accelerometer);
        ::close(humidityTemperature);
        return false;
      }
    ::usleep(100000);


    //config
    char hum_buf[16];

    if(hum_addr == 0x40)
      {
        hum_buf[0] = 0x02;
        hum_buf[1] = 0x10;
        hum_buf[2] = 0x00;
        write(humidityTemperature, hum_buf, 3);
      }
    else
      {
      }

    //
    //Pressure initialization
    //
    double m_a0;
    double m_b1;
    double m_b2;
    double m_c12;
    unsigned short dig_T1;
    short dig_T2;
    short dig_T3;
    unsigned short dig_P1;
    short dig_P2;
    short dig_P3;
    short dig_P4;
    short dig_P5;
    short dig_P6;
    short dig_P7;
    short dig_P8;
    short dig_P9;

    int pressure;
    pressure = ::open("/dev/i2c-1", O_RDWR);
    if(pressure < 0)
      {
        std::cout<<"  Faild to open i2c port"<<std::endl;
        ::close(illumination);
        ::close(accelerometer);
        ::close(humidityTemperature);
        ::close(pressure);
        return false;
      }
    if (ioctl(pressure, I2C_SLAVE, pre_addr) < 0)
      {
        std::cout<<"  Unable to get bus access to talk to slave"<<std::endl;
        std::cout<<"  I2C_SLAVE is 0x60."<<std::endl;
        ::system("sudo i2cdetect -y 1");
        ::close(illumination);
        ::close(accelerometer);
        ::close(humidityTemperature);
        ::close(pressure);
        return false;
      }
    ::usleep(100000);

    char pre_buf[2];
    if(pre_addr == 0x60)
      {

        //Reading coefficient data
        pre_buf[0] = 0x04;//command
        ::write(pressure, pre_buf, 1);
        ::usleep(5000);

        unsigned char coefficientData[8];
        for(int ic=0;ic<8;++ic)
          {
            ::read(pressure, &coefficientData[ic], 1);
            //::usleep(5000);
          }
        /*
        { //for debug
          std::cout<<"  coefficientData  "<<std::flush;
          std::stringstream ss;
          for(int ic=0;ic<8;++ic)
            {
              ss << std::hex << (int)coefficientData[ic] <<" ";
            }
          std::cout<<ss.str()<<std::endl;
        }
        */
    
        unsigned short tempData;
        tempData = ((unsigned short)(coefficientData[0]) << 8) + coefficientData[1];
    /*
        { //for debug
          std::cout<<std::hex<<"  tmpDt = "<< tempData <<std::endl;
          std:: cout << resetiosflags(std::ios_base::basefield);
        }
    */
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
    /*
        std::cout<<"  a0 = "<< m_a0 <<std::endl;
        std:: cout << resetiosflags(std::ios_base::floatfield);
    */
        }
        tempData = ((unsigned short)(coefficientData[2]) << 8) + coefficientData[3];
    /*
        { //for debug 
          std::cout<<std::hex<<"  tmpDt = "<< tempData <<std::endl;
          std:: cout << resetiosflags(std::ios_base::basefield);
        }
    */
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
    /*
        std::cout<<"  b1 = "<< m_b1 <<std::endl;
        std:: cout << resetiosflags(std::ios_base::floatfield);
    */
        }
        tempData = ((unsigned short)(coefficientData[4]) << 8) + coefficientData[5];
    /*
        { // for debug
          std::cout<<std::hex<<"  tmpDt = "<< tempData <<std::endl;
          std:: cout << resetiosflags(std::ios_base::basefield);
        }
    */
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
    /*
        std::cout<<"  b2 = "<< m_b2 <<std::endl;
        std:: cout << resetiosflags(std::ios_base::floatfield);
    */
        }

        tempData = ((unsigned short)(coefficientData[6]) << 8) + coefficientData[7];
    /*
        { //for debug
          std::cout<<std::hex<<"  tmpDt = "<< tempData <<std::endl;
          std:: cout << resetiosflags(std::ios_base::basefield);
        }
    */
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
    /*
        std::cout<<"  c12 = "<< m_c12 <<std::endl;
        std:: cout << resetiosflags(std::ios_base::floatfield);
    */
    
        }
      }
    else
      {
        //
        //BMP280
        //

        //ctrl_meas_reg
        pre_buf[0] = 0xf4;
        pre_buf[1] = 0x27;
        ::write(pressure, pre_buf, 2);

        //config_reg
        pre_buf[0] = 0xf5;
        pre_buf[1] = 0xb0;
        ::write(pressure, pre_buf, 2);

        //read calibration data for temperature
        pre_buf[0] = 0x88;
        ::write(pressure, pre_buf, 1);
        ::read(pressure, pre_buf, 2);
        dig_T1 = (((short)pre_buf[1]<<8)|((short)pre_buf[0]));
        
        pre_buf[0] = 0x8a;
        ::write(pressure, pre_buf, 1);
        ::read(pressure, pre_buf, 2);
        dig_T2 = (((short)pre_buf[1]<<8)|((short)pre_buf[0]));
    
        pre_buf[0] = 0x8c;
        ::write(pressure, pre_buf, 1);
        ::read(pressure, pre_buf, 2);
        dig_T3 = (((short)pre_buf[1]<<8)|((short)pre_buf[0]));
    
        //read calibration data for pressure
        pre_buf[0] = 0x8e;
        ::write(pressure, pre_buf, 1);
        ::read(pressure, pre_buf, 2);
        dig_P1 = (((short)pre_buf[1]<<8)|((short)pre_buf[0]));
    
        pre_buf[0] = 0x90;
        ::write(pressure, pre_buf, 1);
        ::read(pressure, pre_buf, 2);
        dig_P2 = (((short)pre_buf[1]<<8)|((short)pre_buf[0]));
      
        pre_buf[0] = 0x92;
        ::write(pressure, pre_buf, 1);
        ::read(pressure, pre_buf, 2);
        dig_P3 = (((short)pre_buf[1]<<8)|((short)pre_buf[0]));
        
        pre_buf[0] = 0x94;
        ::write(pressure, pre_buf, 1);
        ::read(pressure, pre_buf, 2);
        dig_P4 = (((short)pre_buf[1]<<8)|((short)pre_buf[0]));
    
        pre_buf[0] = 0x96;
        ::write(pressure, pre_buf, 1);
        ::read(pressure, pre_buf, 2);
        dig_P5 = (((short)pre_buf[1]<<8)|((short)pre_buf[0]));
    
        pre_buf[0] = 0x98;
        ::write(pressure, pre_buf, 1);
        ::read(pressure, pre_buf, 2);
        dig_P6 = (((short)pre_buf[1]<<8)|((short)pre_buf[0]));
    
        pre_buf[0] = 0x9a;
        ::write(pressure, pre_buf, 1);
        ::read(pressure, pre_buf, 2);
        dig_P7 = (((short)pre_buf[1]<<8)|((short)pre_buf[0]));
    
        pre_buf[0] = 0x9c;
        ::write(pressure, pre_buf, 1);
        ::read(pressure, pre_buf, 2);
        dig_P8 = (((short)pre_buf[1]<<8)|((short)pre_buf[0]));
    
        pre_buf[0] = 0x9e;
        ::write(pressure, pre_buf, 1);
        ::read(pressure, pre_buf, 2);
        dig_P9 = (((short)pre_buf[1]<<8)|((short)pre_buf[0]));
      }

    //
    //1-wire initialization
    //
    std::cout<<"-1wire initialization"<<std::endl;
    std::string unique_code =""; 
    struct dirent* ent; 
    DIR* dir_ptr(::opendir("/sys/bus/w1/devices/"));
    if (dir_ptr == 0) 
      { 
        ::close(illumination);
        ::close(accelerometer);
        ::close(humidityTemperature);
        ::close(pressure);
        return false;
      }
    while ((ent = ::readdir(dir_ptr)) != 0)
      {
        std::string fname(ent->d_name);
        if((fname.compare("w1_bus_master1") == 0)|| 
            (fname.compare(".") == 0) ||
            (fname.compare("..") == 0) ||
            ((int)fname.rfind("28-") != 0))
          {
          }
        else
          { 
            unique_code = ent->d_name; 
            break;
          }

      }
    ::closedir(dir_ptr);
    if(unique_code.length()==0)
      {
        std::cout<<"  not found devices"<<std::endl;
        ::close(illumination);
        ::close(accelerometer);
        ::close(humidityTemperature);
        ::close(pressure);
        return false;
      }
    std::cout<<"  unique_code = "<<unique_code<<std::endl;

    //
    //Uart initialization
    //
    int uart;
    uart = ::open("/dev/ttyS0", O_RDWR | O_NOCTTY);
    if(uart < 0)
      {
        std::cout<<"  Faild to open UART"<<std::endl;
        ::close(illumination);
        ::close(accelerometer);
        ::close(humidityTemperature);
        ::close(pressure);
        ::close(uart);
        return false;
      }
    struct termios old_term_io;
    struct termios new_term_io;
    ::tcgetattr(uart, &old_term_io);
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
    //new_term_io.c_cc[VMIN] = 1;
    new_term_io.c_cc[VMIN] = 0;
    ::tcflush(uart, TCIFLUSH);
    ::tcsetattr(uart, TCSANOW, &new_term_io);
  
    std::cout<<""<<std::endl;
    std::cout<<"** Press Enter key to start the demonstration. **"<<std::endl;
    getchar();
    //
    //get data
    //
    for(;;)
      {
        if(g_sig == 1)
          {
            break;
          }
        //
        // Get Temperature 
        //
        std::string str_dir("/sys/bus/w1/devices/");
        str_dir = str_dir + unique_code + "/w1_slave";
        std::ifstream ifs( str_dir.c_str() );
        std::string line_str;
        std::string::size_type pos(0);
        std::getline(ifs, line_str);
        std::getline(ifs, line_str);
        pos = line_str.find("t=");
        float value;
        if(pos != std::string::npos)
          {
            std::string value_str = line_str.substr(pos+2);
            std::stringstream ss(value_str);
            ss >> value;
            value = value / 1000.0;
          }
          std::cout <<std::fixed<<std::setprecision(2)<< value << "C " << std::flush;
        //
        // Get Humidity
        //
        if(hum_addr == 0x40)
          {
            hum_buf[0] = 0x00;
            ::write(humidityTemperature, hum_buf, 1);
            ::usleep(20000);

            size_t len = ::read(humidityTemperature, hum_buf, 4);

            short temperature_val = (((short)hum_buf[0x00]<<8)|((short)hum_buf[0x01]));
            unsigned short humidity_val = (((short)hum_buf[0x02]<<8)|((short)hum_buf[0x03]));

            std::stringstream hum_ss;
            double temperature = ((double)temperature_val*165.0/65536.0)-40.0;
            double humidity = ((double)humidity_val*100.0/65536.0);
            hum_ss <<std::fixed<<std::setprecision(2)<< humidity << "% " ;

            std::cout << hum_ss.str() << std::flush;
          }
        else
          {
            hum_buf[0] = 0x2C;
            hum_buf[1] = 0x06;
            ::write(humidityTemperature, hum_buf, 2);
            ::usleep(20000);

            size_t len = ::read(humidityTemperature, hum_buf, 6);

            short temperature_val = (((short)hum_buf[0x00]<<8)|((short)hum_buf[0x01]));
            unsigned short humidity_val = (((short)hum_buf[0x03]<<8)|((short)hum_buf[0x04]));


            std::stringstream hum_ss;
            double temperature = ((double)temperature_val*175.0/65536.0)-45.0;
            double humidity = ((double)humidity_val*100.0/65536.0);

            hum_ss <<std::fixed<<std::setprecision(2)<< humidity << "% " ;

            std::cout << hum_ss.str() << std::flush;
          }
        //
        //Gets Barometer
        //
        //Command to I2C Start Conversion
        if(pre_addr == 0x60)
          {
            pre_buf[0] = 0x12;
            pre_buf[1] = 0x00;
            ::write(pressure, pre_buf, 2);
            //::usleep(15000);
            ::usleep(1600);

            //pre_buf[0] = 0x00;//command
            //::write(pressure, pre_buf, 1);
            //::usleep(5000);

            unsigned char adcCounts[4];
            for(int ic=0;ic<4;++ic)
              {
                pre_buf[0] = (char)ic;
                ::write(pressure, pre_buf, 1);
                //::usleep(5000);
                ::read(pressure, &adcCounts[ic], 1);
                ::usleep(5000);
              }

            unsigned short tempData;
            tempData = ((unsigned short)(adcCounts[0]) << 8) + adcCounts[1];
            double padc;
            {
            //unsigned short integer = (tempData & 0xffc0) >> 6;
            unsigned short integer = (tempData >> 6) & 0x3ff;

            padc = (double)integer;

            }
            tempData = ((unsigned short)(adcCounts[2]) << 8) + adcCounts[3];
            double tadc;
            {
            unsigned short integer = (tempData & 0xffc0) >> 6;

            tadc = (double)integer;

            }
            double pcomp = m_a0+ ( m_b1+ m_c12 * tadc ) * padc + m_b2 * tadc; 
            double pressure = pcomp * ((115.0-50.0)/1023.0) + 50.0;
            pressure = pressure * 10;
            std::cout <<std::fixed<<std::setprecision(2)<< pressure << "hPa " << std::flush;
          }
        else
          {
            //
            //BMP280
            //

            //read data registers for temperature
            pre_buf[0] = 0xfa;
            ::write(pressure, pre_buf, 1);
            ::read(pressure, pre_buf, 3);
            long temp_raw = ((long)(pre_buf[0]<<12)&0xff000)|((long)(pre_buf[1]<<4)&0x0ff0)|((long)(pre_buf[2]>>4)&0x0f);

            //read data registers for pressure
            pre_buf[0] = 0xf7;
            ::write(pressure, pre_buf, 1);
            ::read(pressure, pre_buf, 3);
            long pres_raw = ((long)(pre_buf[0]<<12)&0xff000)|((long)(pre_buf[1]<<4)&0x0ff0)|((long)(pre_buf[2]>>4)&0x0f);
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
                std::cout <<std::fixed<<std::setprecision(2)<< pressure << "hPa " << std::flush;
          }


        //
        //Gets the Accelerometer
        //
        acc_buf[0] = 0x32;
        ::write(accelerometer, acc_buf, 1);
        ::read(accelerometer, acc_buf, 6);
        short x_val = (((short)acc_buf[1]<<8)|((short)acc_buf[0]));
        short y_val = (((short)acc_buf[3]<<8)|((short)acc_buf[2]));
        short z_val = (((short)acc_buf[5]<<8)|((short)acc_buf[4]));

        std::stringstream ss;
        ss << std::fixed<<std::setprecision(2)<<(double)x_val*0.0039 << "g " << (double)y_val*0.0039 << "g " << (double)z_val*0.0039 <<"g ";
        std::cout << ss.str() << std::flush;
        
        //
        //Gets Illumination
        //
        
        //set gain
        ill_buf[0] = 0x81;
        ill_buf[1] = 0x12;
        ::write(illumination, ill_buf, 2);
        usleep(800000);

        //get
        ill_buf[0] = 0xac;
        ::write(illumination, ill_buf, 1);
        ::read(illumination, ill_buf, 2);
    
        unsigned short full = (((short)ill_buf[0x01]<<8)|((short)ill_buf[0x00]));

        ill_buf[0] = 0xae;
        ::write(illumination, ill_buf, 1);
        ::read(illumination, ill_buf, 2);
    
        unsigned short ir = (((short)ill_buf[0x01]<<8)|((short)ill_buf[0x00]));
        double ratio;
        if(full==0)
          {
            ratio = 9999.0;
          }
        else
          {
            ratio = ((double)ir/(double)full);
          }

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
        std::cout<< std::fixed<<std::setprecision(2)<< (double)lux << "lx "<<std::flush;

        //
        //Gets GPS
        //
        std::string ret;
        char cbuf;
        char ubuf[256];
        ubuf[0] = '\0';
        int rp = 0;
        int step = 0;
        for(;;)
          {
            size_t len = read(uart, (char *)&cbuf, 1);
            if(len == 0)
              {
                ubuf[0] = 'N';
                ubuf[1] = 'C';
                ubuf[2] = '\0';
                rp = 2;
                break;
              }
            switch(step)
              {
              case 0:
                if(cbuf == '$')
                  {
                    ubuf[0] = cbuf;
                    rp = 1;
                    step = 1;
                  }
                break;
              case 1:
                ubuf[rp] = cbuf;
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

        ubuf[rp] = '\0';
        ret = std::string(ubuf);
        std::vector<std::string> vstr;
        std::stringstream u_ss(ret);
        std::string buffer;
        while( std::getline(u_ss, buffer, ',') ) 
          {
            vstr.push_back(buffer);
          }
        double lat = 0.0;
        double lon = 0.0;
        if(vstr[0].compare("$GPGGA")==0)
          {
            if((vstr[2].length() != 0) && (vstr[4].length() !=0))
              {
                lat = std::stod(vstr[2]);
                lon = std::stod(vstr[4]);
                lat = lat /100.0;
                lon = lon /100.0;
                std::cout<<" "<<vstr[0]<<" "<<lat<<"N "<<lon<<"E "<<std::flush;
                //std::cout<<" "<<vstr[2]<<"N "<<vstr[4]<<"E "<<std::flush;
              } 
            else
              {
                std::cout<<" "<<vstr[0]<<std::flush;
              }
          }
        else if(vstr[0].compare("$GPRMC")==0)
          {
            if((vstr[3].length() != 0) && (vstr[5].length() != 0))
              {
                lat = std::stod(vstr[3]);
                lon = std::stod(vstr[5]);
                lat = lat /100.0;
                lon = lon /100.0;
                std::cout<<" "<<vstr[0]<<" "<<lat<<"N "<<lon<<"E "<<std::flush;
              }
            else
              {
                  std::cout<<" "<<vstr[0]<<std::flush;
              }
          }
        else
          {
            std::cout<<" "<<vstr[0]<<" "<<std::flush;
          }

        
        //wait
        std::cout << std::endl;
        //::usleep(300000);

      }
    //
    //Termination 
    //
    std::cout<<""<<std::endl;
    std::cout<<"Termination"<<std::endl;
    ::close(illumination);
    ::close(accelerometer);
    ::close(humidityTemperature);
    ::close(pressure);
    ::tcsetattr(uart, TCSANOW, &old_term_io);
    ::close(uart);
}

