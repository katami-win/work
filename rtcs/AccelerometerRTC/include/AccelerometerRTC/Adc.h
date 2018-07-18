// -*- C++ -*-
/*!
 * @file Adc.h
 * @brief Controls ADC.
 * @date $Date: $
 *
 * $Id: Adc.h 180 2014-06-17 01:10:29Z pi $
 *
 */

#ifndef ADC_H 
#define ADC_H

#include <string>



namespace WEIApp
{
  /*!
   * @class Adc
   * @brief Controls ADC.
   *
   * The interface with a device is SPI.
   *
   */
  class Adc
  {

  public:
    /*!
     * @brief Constructor
     * @param none
     */
    Adc();
    /*!
     * @brief Destructor
     * @param none
     */
    virtual ~Adc(void);
    /*!
     * @brief Adc initialization
     * @return true: Success
     *         false:Failure
     */
    virtual bool initAdc();
    /*!
     * @brief Shutdown Adc
     * 
     */
    virtual void shutdownAdc();

    /*!
     * @brief Gets the Adc
     * @param channel
     * @return AD value
     * 
     */
    virtual unsigned long getValue(int channel);

    /*!
     * @brief Gets the Adc
     * @param channel
     * @return AD value
     * 
     */
    //virtual std::string getValue(int channel);

    /*!
     * @brief Gets Moisture
     * @param none
     * @return percent
     * 
     */
    virtual int getMoisture();
    /*!
     * @brief Gets luminosit 
     * @param none
     * @return  lux
     * 
     */
    virtual float getLuminosity();


  protected:
  private:
    std::string m_spiFilename; 
    int m_adc;
    unsigned char m_mode;
    unsigned char m_bits;
    unsigned int m_speed;



  }; 
}; // namespace 
#endif // ADC_H 

