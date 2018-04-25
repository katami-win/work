// -*- C++ -*-
/*!
 * @file HumidityTemperature.h
 * @brief Controls HumidityTemperature.
 * @date $Date: $
 *
 * $Id: $
 *
 */

#ifndef HUMIDITYTEMPERATURE2_H 
#define HUMIDITYTEMPERATURE2_H

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


  }; 
}; // namespace 
#endif // HUMIDITYTEMPERATURE_H 

