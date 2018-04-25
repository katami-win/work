// -*- C++ -*-
/*!
 * @file Clcd.h
 * @brief Controls Character LCD.
 * @date $Date: $
 *
 * $Id: Clcd.h 180 2014-06-17 01:10:29Z pi $
 *
 */

#ifndef CLCD_H 
#define CLCD_H

#include <string>



namespace WEIApp
{
  /*!
   * @class Clcd
   * @brief Controls Character LCD.
   *
   * A device is ST7032i.
   * (Two 8-character lines.)
   * iThe interface with a device is I2C.
   *
   */
  class Clcd
  {

  public:
    /*!
     * @brief Constructor
     * @param none
     */
    Clcd();
    /*!
     * @brief Destructor
     * @param none
     */
    virtual ~Clcd(void);
    /*!
     * @brief Clcd initialization
     * @return true: Success
     *         false:Failure
     */
    virtual bool initClcd();
    /*!
     * @brief Shutdown Clcd
     * 
     */
    virtual void shutdownClcd();

    /*!
     * @brief displays a character string on CLCD.
     * @param line line number
     *        str  string
     * 
     */
    virtual void printString(int line, std::string str);



  protected:
  private:
    void LCD_init(void);
    void LCD_write(unsigned char rs, unsigned char data);
    void LCD_clear(void);
    void LCD_setCursor(unsigned char col, unsigned char row);
    void LCD_putc(unsigned char c);
    void LCD_puts(const char *str);


    std::string m_i2cFilename; 
    int m_lcdAddress;
    int m_lcd;
    int m_status;
    bool m_is_indicating;
    int m_indicatingCount;
    int m_count;


  }; 
}; // namespace 
#endif // CLCD_H 

