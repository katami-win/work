// -*- C++ -*-
/*!
 * @file   OneWireTests.cpp
 * @brief  OneWire test class
 * @date   $Date: 2014-06-17 10:14:05 +0900 (Tue, 17 Jun 2014) $
 *
 * $Id: OneWireTests.cpp 182 2014-06-17 01:14:05Z pi $
 *
 */

/*
 * $Log: $
 */

#ifndef OneWireTests_cpp
#define OneWireTests_cpp

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "OneWire.h"

/*!
 * @class OneWireTests class
 * @brief OneWire test
 */
namespace OneWire
{
  class OneWireTests
  {
  public:
    /*!
     * @brief Constructor
     */
    OneWireTests()
    {
    }
    /*!
     * @brief Destructor
     */
    ~OneWireTests()
    {
    }
    void test_getDevices()
    {
      std::cout<<"getDevices Test"<<std::endl;
      WEIApp::OneWire onewire;
      std::vector<std::string> devies = onewire.getDevices();
      if(!devies.empty())
        {
          std::vector<std::string>::iterator it(devies.begin());
          while (it != devies.end())
            {
              std::cout<<*it<<std::endl;
              ++it;
            }
        }
      else
        {
          std::cout<<"error."<<std::endl;
          std::cout<<"Devices are non-connection."<<std::endl;
        }

    }
    void test_getValue()
    {
      std::cout<<"getValue Test"<<std::endl;
      WEIApp::OneWire onewire;
      std::vector<std::string> devies = onewire.getDevices();
      if(!devies.empty())
        {
         while(1)
           {
            std::vector<std::string>::iterator it(devies.begin());
            while (it != devies.end())
              {
                std::cout<<std::setw(20)<<std::left<<*it;
                std::cout<<onewire.getValue(*it)<<std::endl;;
                ++it;
              }
          }
        }
      else
        {
          std::cout<<"error."<<std::endl;
          std::cout<<"Devices are non-connection."<<std::endl;
        }
    }
  };
};
int main(int argc, char* argv[])
{
  std::cout<<"OneWireTests"<<std::endl;
  OneWire::OneWireTests tests;
  tests.test_getDevices();
  tests.test_getValue();

}
#endif // GpioTests_cpp
