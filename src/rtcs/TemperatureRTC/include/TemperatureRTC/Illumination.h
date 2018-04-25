// -*- C++ -*-
/*!
 * @file Illumination.h
 * @brief Controls Illumination.
 * @date $Date: $
 *
 * $Id: $
 *
 */

#ifndef ILLUMINATION_H 
#define ILLUMINATION_H

#include <string>


namespace WEIApp
{
  /*!
   * @class Illumination
   * @brief Controls Illumination.
   *
   * A device is TSL2561.
   * The interface with a device is I2C.
   *
   */
  class Illumination
  {

  public:
    /*!
     * @brief Constructor
     * @param none
     */
    Illumination();
    /*!
     * @brief Destructor
     * @param none
     */
    virtual ~Illumination(void);
    /*
     * @brief Illumination initialization
     * @return true: Success
     *         false:Failure
     */
    virtual bool initIllumination();
    /*!
     * @brief Shutdown Illumination
     * 
     */
    virtual void shutdownIllumination();

    /*!
     * @brief Sets the Gain
     * @param gain 
     * 
     */
    virtual void setGain(int gain = 1);
    /*!
     * @brief get the full spectrum
     * @param none
     * @return full spectrum
     * 
     */
    virtual unsigned short getFullSpectrum();
    /*!
     * @brief get the infrared
     * @param none
     * @return infrared
     * 
     */
    virtual unsigned short getInfrared();
    /*!
     * @brief Gets the Illumination
     * @param none
     * @return 
     * 
     */
    virtual std::string getValue();

    /*!
     * @brief Gets the Illumination
     * @param none
     * @return 
     * 
     */
    //virtual long getValue();



  protected:
  private:

    std::string m_i2cFilename; 
    int m_illuminationAddress;
    int m_illumination;
    
    int m_gain;

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
#endif // ILLUMINATION_H

