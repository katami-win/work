// -*- C++ -*-
/*!
 * @file Uart.h
 * @brief Controls UART
 * @date $Date: $
 *
 * $Id: Gpio.h 180 2014-06-17 01:10:29Z pi $
 *
 */

#ifndef UART_H 
#define UART_H

#include <string>
#include <termios.h>
#include <unistd.h>


namespace WEIApp
{
  /*!
   * @class Uart
   * @brief Controls UART
   *
   *
   */
  class Uart
  {

  public:
    /*!
     * @brief Constructor
     * @param none
     */
    Uart();
    /*!
     * @brief Destructor
     * @param none
     */
    virtual ~Uart(void);
    /*!
     * @brief Uart initialization
     * @return true: Success
     *         false:Failure
     */
    virtual bool initUart();
    /*!
     * @brief Shutdown Uart
     * 
     */
    virtual void shutdownUart();
    /*!
     * @brief read
     * 
     */
    virtual std::string readGPGGA();




  protected:
  private:
    struct termios old_term_io;
    int m_uart;
    std::string m_i2cFilename; 
    int m_status;
    bool m_is_indicating;
    int m_indicatingCount;
    int m_count;


  }; 
}; // namespace 
#endif // UART_H 

