// -*- C++ -*-
/*!
 * @file Pressure.h
 * @brief Controls Pressure.
 * @date $Date: $
 *
 * $Id: Pressure.h 180 2014-06-17 01:10:29Z pi $
 *
 */

#ifndef PRESSURE_H 
#define PRESSURE_H

#include <string>



namespace App
{
  /*!
   * @class Pressure
   * @brief Controls Pressure.
   *
   * A device is BMP085.
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

    std::string m_i2cFilename; 
    int m_pressureAddress;
    int m_pressure;
    
    double m_a0;
    double m_b1;
    double m_b2;
    double m_c12;

/*
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
*/

  }; 
}; // namespace 
#endif // PRESSURE_H 

