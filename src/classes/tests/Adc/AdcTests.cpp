// -*- C++ -*-
/*!
 * @file   AdcTests.cpp
 * @brief  Adc test class
 * @date   $Date: 2014-06-17 10:14:05 +0900 (Tue, 17 Jun 2014) $
 *
 * $Id: AdcTests.cpp 182 2014-06-17 01:14:05Z pi $
 *
 */

/*
 * $Log: $
 */

#ifndef AdcTests_cpp
#define AdcTests_cpp

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "Adc.h"

/*!
 * @class AdcTests class
 * @brief Adc test
 */
namespace Adc
{
  class AdcTests
  {
  public:
    /*!
     * @brief Constructor
     */
    AdcTests()
    {
    }
    /*!
     * @brief Destructor
     */
    ~AdcTests()
    {
    }
    void test_getValue()
    {
      std::cout<<"getValue Test"<<std::endl;
      WEIApp::Adc adc;
      adc.initAdc();
/*
      std::cout<<adc.getValue(0)<<std::endl;;
      std::cout<<adc.getValue(1)<<std::endl;;
*/
    }
    void test_getMoisture()
    {
      std::cout<<"getMoisture Test"<<std::endl;
      WEIApp::Adc adc;
      adc.initAdc();
      std::cout<<adc.getMoisture()<<std::endl;;
    }
    void test_getLuminosity()
    {
      std::cout<<"getLuminosity Test"<<std::endl;
      WEIApp::Adc adc;
      adc.initAdc();
      std::cout<<adc.getLuminosity()<<std::endl;;
    }
    void test_getValue2()
    {
      std::cout<<"getValue Test"<<std::endl;
      WEIApp::Adc adc;
      adc.initAdc();
      std::cout<<adc.getValue(0)<<std::endl;;
      std::cout<<adc.getValue(1)<<std::endl;;
    }
  };
};
int main(int argc, char* argv[])
{
  std::cout<<"AdcTests"<<std::endl;
  Adc::AdcTests tests;
  tests.test_getValue();
  //tests.test_getMoisture();
  //tests.test_getLuminosity();
  //tests.test_getValue2();
}
#endif // GpioTests_cpp
