// -*- C++ -*-
/*!
 * @file Clcd.cpp
 * @brief Controls Character LCD.
 * @date $Date: $
 *
 * $Id: $
 *
 */
#include <string>
#include <iostream>
#include <iomanip>

#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>

#include <unistd.h>

#include <wiringPi.h>

#include <Clcd.h>

#define LCD_CONTRAST 100
#define LCD_RS_CMD (0x00)
#define LCD_RS_DATA (0x40)
#define LCD_CMD_CLEAR (0x01)
#define LCD_CMD_HOME (0x03)

namespace WEIApp
{
  #define LCD_ADDRESS 0x3e
  //#define LCD_ADDRESS 0x7c

  /*!
   * @brief Constructor
   * @param none
   */
  Clcd::Clcd()
  {
    m_lcd = (int)NULL;
    m_i2cFilename = "/dev/i2c-1";
    m_lcdAddress = LCD_ADDRESS;
    m_status = 0;
    m_is_indicating = false;
    m_indicatingCount = 60;
    m_count = 0;
  }
  /*!
   * @brief Destructor
   * @param none
   */
  Clcd::~Clcd(void)
  {
  }
  /*!
   * @brief Clcd initialization
   * @return true: Success
   *         false:Failure
   */
  bool Clcd::initClcd()
  {
    m_lcd = ::open(m_i2cFilename.c_str(), O_RDWR);
    if(m_lcd < 0)
      {
        std::cout<<"Faild to open i2c port"<<std::endl;
        return false;
      }
    if (ioctl(m_lcd, I2C_SLAVE, m_lcdAddress) < 0)
      {
        std::cout<<"Unable to get bus access to talk to slave"<<std::endl;
        return false;
      }
    delay(100);

    delay(40);
    unsigned char buf[2];
    buf[0] = LCD_RS_CMD;
    buf[1] = 0b00111000;
    if (::write(m_lcd, buf, (size_t)2) != 2)
      {
        std::cout<<"Error writeing to i2c slave"<<std::endl;
        return false;
      }
    LCD_init();
    LCD_clear();
    m_status = 1;
    return true;

  }
  /*!
   * @brief Shutdown Clcd
   * 
   */
  void Clcd::shutdownClcd()
  {
  }

  /*!
   * @brief displays a character string on CLCD.
   * @param line line number
   *        str  string
   * 
   */
  void Clcd::printString(int line, std::string str)
  {
    if(m_status == 1)
      {
        LCD_setCursor(0, line);
        LCD_puts(str.c_str());
      }
  }



  void Clcd::LCD_write(unsigned char rs, unsigned char data)
  {
    unsigned char buf[2];

    if (rs == LCD_RS_CMD || rs == LCD_RS_DATA)
      {
        buf[0] = rs;
        buf[1] = data;
        if (::write(m_lcd, buf, (size_t)2) != 2)
          {
            std::cout<<"Error writeing to i2c slave"<<std::endl;
          }
      }
    else
      {
        std::cout<<"Error RS"<<std::endl;
      }
  }

  void Clcd::LCD_setCursor(unsigned char col, unsigned char row)
  {
    unsigned char offset[] = {0x00, 0x40};
    
    if (row > 1)
      {
        row = 1;
      }
    if (col > 16)
      {
        col = 16;
      }
    
    LCD_write(LCD_RS_CMD, 0x80 | (col + offset[row]));
  }

  void Clcd::LCD_putc(unsigned char c)
  {
      LCD_write(LCD_RS_DATA, c);
  }

  void Clcd::LCD_puts(const char *str)
  {
    for (int ic = 0; ic < 16; ++ic)
      {
        if (str[ic] == 0x00)
          {
            break;
          }
        else
          {
            LCD_putc((unsigned int)str[ic]);
          }
      }
  }

  void Clcd::LCD_clear(void)
  {
    LCD_write(LCD_RS_CMD, LCD_CMD_CLEAR);
    delay(2);
    LCD_write(LCD_RS_CMD, LCD_CMD_HOME);
    delay(2);
  }

  void Clcd::LCD_init(void)
  {
    delay(40);
    // Function Set 8bit bus mode, 
    //              2-line mode,normal font,
    //              normal instruction mode
    LCD_write(LCD_RS_CMD, 0b00111000);
    delay(1);
    // Function Set extension instruction mode
    LCD_write(LCD_RS_CMD, 0b00111001);
    delay(1);
    // Set Internal OSC frequency(extension instruction mode)
    LCD_write(LCD_RS_CMD, 0b00010100);
    delay(1);
    // Contrast set(extension instruction mode)
    LCD_write(LCD_RS_CMD, 0b01110000 | (LCD_CONTRAST & 0xF));
    delay(1);
    // Power/ICON/Contrast set(extension instruction mode)
    LCD_write(LCD_RS_CMD, 0b01011100 | ((LCD_CONTRAST >> 4) & 0x3));
    delay(1);
    // Follower control internal follower on, 
    LCD_write(LCD_RS_CMD, 0b01101100);

    delay(300);

    // Function Set normal instruction mode
    LCD_write(LCD_RS_CMD, 0b00111000);
    delay(1);
    // Display On/Off Set Display On
    LCD_write(LCD_RS_CMD, 0b00001100);
    delay(1);
    // Clear Display
    //LCD_write(LCD_RS_CMD, 0b00001100);
    LCD_write(LCD_RS_CMD, 0b00000001);

    delay(2);
    
  }


}; // namespace 

