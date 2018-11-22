// -*- C++ -*-
/*!
 * @file Pressure.h
 * @brief Controls Pressure.
 * @date $Date: $
 * @author WIN ELECTRONIC INDUSTRIES
 *
 * $Id: Pressure.h 180 2014-06-17 01:10:29Z pi $
 *
 */

#ifndef PRESSURE_H 
#define PRESSURE_H

#include <string>



namespace WEIApp
{
  /*!
   * @class Pressure
   * @brief Controls Pressure.
   *
   * A device is MPL115A2
   * The interface with a device is I2C.
   *
   */
  class Pressure
  {

  public:
    /*!
     * @brief Constructor
     * @param none
     */
    Pressure();
    /*!
     * @brief Destructor
     * @param none
     */
    virtual ~Pressure(void);
    /*!
     * @brief Pressure initialization
     * @return true: Success
     *         false:Failure
     */
    virtual bool initPressure();
    /*!
     * @brief Shutdown Pressure
     * 
     */
    virtual void shutdownPressure();

    /*!
     * @brief Gets the Pressure
     * @param none
     * @return press. in Pa
     * 
     */
    virtual double getValue();



  protected:
  private:
    int getI2cAddress(std::string str);

    std::string m_i2cFilename; 
    int m_pressureAddress;
    int m_pressure;
    
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


  }; 
}; // namespace 
#endif // PRESSURE_H 

