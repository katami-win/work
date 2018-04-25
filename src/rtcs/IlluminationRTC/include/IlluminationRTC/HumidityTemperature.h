// -*- C++ -*-
/*!
 * @file HumidityTemperature.h
 * @brief Controls HumidityTemperature.
 * @date $Date: $
 *
 * $Id: $
 *
 */

#ifndef HUMIDITYTEMPERATURE_H 
#define HUMIDITYTEMPERATURE_H

#include <string>


namespace WEIApp
{
  /*!
   * @class HumidityTemperature
   * @brief Controls HumidityTemperature.
   *
   * A device is HDC1000.
   * The interface with a device is I2C.
   *
   */
  class HumidityTemperature
  {

  public:
    /*!
     * @brief Constructor
     * @param none
     */
    HumidityTemperature();
    /*!
     * @brief Destructor
     * @param none
     */
    virtual ~HumidityTemperature(void);
    /*
     * @brief HumidityTemperature initialization
     * @return true: Success
     *         false:Failure
     */
    virtual bool initHumidityTemperature();
    /*!
     * @brief Shutdown HumidityTemperature
     * 
     */
    virtual void shutdownHumidityTemperature();

    /*!
     * @brief Gets the HumidityTemperature
     * @param none
     * @return 
     * 
     */
    virtual std::string getValue();

    /*!
     * @brief Gets the HumidityTemperature
     * @param none
     * @return 
     * 
     */
    //virtual long getValue();



  protected:
  private:

    std::string m_i2cFilename; 
    int m_humidityTemperatureAddress;
    int m_humidityTemperature;

    short m_ac1;
    short m_ac2;
    short m_ac3;
    unsigned short m_ac4;
    unsigned short m_ac5;
    unsigned short m_ac6;
    short m_b1;
    short m_b2;
    short m_mb;
    short m_mc;
    short m_md;

  }; 
}; // namespace 
#endif // HUMIDITYTEMPERATURE_H 

