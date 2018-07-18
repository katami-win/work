// -*- C++ -*-
/*!
 * @file   PressureTests.cpp
 * @brief  Pressure test class
 * @date   $Date: 2014-06-17 10:14:05 +0900 (Tue, 17 Jun 2014) $
 *
 * $Id: PressureTests.cpp 182 2014-06-17 01:14:05Z pi $
 *
 */

/*
 * $Log: $
 */

#ifndef PressureTests_cpp
#define PressureTests_cpp

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include <unistd.h>

#include "Pressure.h"

/*!
 * @class PressureTests class
 * @brief Pressure test
 */
namespace Pressure
{
  class PressureTests
  {
  public:
    /*!
     * @brief Constructor
     */
    PressureTests()
    {
    }
    /*!
     * @brief Destructor
     */
    ~PressureTests()
    {
    }
    void test_getValue()
    {
      std::cout<<"getValue Test"<<std::endl;
      WEIApp::Pressure pressure;
      pressure.initPressure();
      while(1)
        {  
          std::cout<<pressure.getValue()<<std::endl;;
          ::sleep(1);
        }
    }
  };
};
int main(int argc, char* argv[])
{
  std::cout<<"PressureTests"<<std::endl;
  Pressure::PressureTests tests;

  tests.test_getValue();
}
#endif // GpioTests_cpp
