// -*- C++ -*-
/*!
 * @file   HumidityTemperatureTests.cpp
 * @brief  HumidityTemperature test class
 * @date   $Date: $
 *
 * $Id: $
 *
 */

/*
 * $Log: $
 */

#ifndef HumidityTemperatureTests_cpp
#define HumidityTemperatureTests_cpp

#include <iostream>

#include <unistd.h>

#include "HumidityTemperature.h"
#include "Task.h" 

/*!
 * @class HumidityTemperatureTests class
 * @brief HumidityTemperature test
 */
namespace HumidityTemperature
{
  class HumidityTemperatureTests
    : public WEIApp::Task
  {
  public:
    bool m_keys;
    /*!
     * @brief Constructor
     */
    HumidityTemperatureTests()
    {
    }
    /*!
     * @brief Destructor
     */
    ~HumidityTemperatureTests()
    {
    }
    /*!
     * @brief Service call
     */
    int svc()
    {
      //std::cout<<"svc runs"<<std::endl;
      char c1;
      std::cin.get(c1);
      m_keys = true;
    }
    /*!
     * @brief Create a thread
     */
    void activate()
    {
      Task::activate();
    }
    /*!
     * @brief Finalizing the task
     */
    void finalize()
    {
      Task::finalize();
    }
    void test_getValue()
    {
      std::cout<<"getValue Test"<<std::endl;
      WEIApp::HumidityTemperature humid;
      humid.initHumidityTemperature();
      
      m_keys = false;
      activate(); 

      std::cout<<"Unit Celsius %"<<std::endl;
      while(!m_keys)
        {  
          std::string str = humid.getValue();
          std::cout<< str  <<std::endl;
          ::sleep(1);
        }  
      finalize();
    }
  };
};
int main(int argc, char* argv[])
{
  std::cout<<"HumidityTemperatureTests"<<std::endl;
  HumidityTemperature::HumidityTemperatureTests tests;
  tests.test_getValue();
}
#endif // HumidityTemperatureTests_cpp
