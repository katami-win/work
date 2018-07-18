// -*- C++ -*-
/*!
 * @file Accelerometer.h
 * @brief Controls Accelerometer.
 * @date $Date: $
 *
 * $Id: $
 *
 */

#ifndef ACCELEROMETER_H 
#define ACCELEROMETER_H

#include <string>


namespace WEIApp
{
  /*!
   * @class Accelerometer
   * @brief Controls Accelerometer.
   *
   * A device is adxl345.
   * The interface with a device is I2C.
   *
   */
  class Accelerometer
  {

  public:
    /*!
     * @brief Constructor
     * @param none
     */
    Accelerometer();
    /*!
     * @brief Destructor
     * @param none
     */
    virtual ~Accelerometer(void);
    /*
     * @brief Accelerometer initialization
     * @return true: Success
     *         false:Failure
     */
    virtual bool initAccelerometer();
    /*!
     * @brief Shutdown Accelerometer
     * 
     */
    virtual void shutdownAccelerometer();

    /*!
     * @brief Gets the Accelerometer
     * @param none
     * @return 
     * 
     */
    virtual std::string getValue();

    /*!
     * @brief Gets the Accelerometer
     * @param none
     * @return 
     * 
     */
    //virtual long getValue();



  protected:
  private:

    std::string m_i2cFilename; 
    int m_accelerometerAddress;
    int m_accelerometer;

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
#endif // ACCELEROMETER_H 

