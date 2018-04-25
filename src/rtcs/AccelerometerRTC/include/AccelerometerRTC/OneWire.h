// -*- C++ -*-
/*!
 * @file OneWire.h
 * @brief Controls 1-Wire.
 * @date $Date: $
 *
 * $Id: OneWire.h 180 2014-06-17 01:10:29Z pi $
 *
 */

#ifndef ONEWIRE_H 
#define ONEWIRE_H

#include <string>
#include <vector>


namespace App
{
  /*!
   * @class OneWire
   * @brief Gets the value from devices connected on 1-Wire.
   *
   * Devices are DS18B20 and DHT11.
   *
   */
  class OneWire 
  {

  public:
    /*!
     * @brief Constructor
     * @param nOne
     */
    OneWire();
    /*!
     * @brief Destructor
     * @param none
     */
    virtual ~OneWire(void);
    /*!
     * @brief OneWire initialization
     * @return true: Success
     *         false:Failure
     */
    virtual bool initOneWire();
    /*!
     * @brief Shutdown OneWire
     * 
     */
    virtual void shutdownOneWire();

    /*!
     * @brief Gets the price of the device of an argument.
     * @param str device
     * 
     */
    virtual float getValue(std::string str);

    /*!
     * @brief Gets a list of devices.
     * @param none
     * 
     */
    virtual std::vector<std::string> getDevices();




  protected:
  private:

  }; 
}; // namespace 
#endif // ONEWIRE_H 

