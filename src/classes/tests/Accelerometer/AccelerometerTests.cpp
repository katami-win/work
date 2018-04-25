// -*- C++ -*-
/*!
 * @file   AccelerometerTests.cpp
 * @brief  Accelerometer test class
 * @date   $Date: $
 *
 * $Id: $
 *
 */

/*
 * $Log: $
 */

#ifndef AccelerometerTests_cpp
#define AccelerometerTests_cpp

#include <iostream>
#include <iomanip>
#include <vector>

#include <unistd.h>

#include "Accelerometer.h"
#include "Task.h" 
#include "Split.h" 

/*!
 * @class AccelerometerTests class
 * @brief Accelerometer test
 */
namespace Accelerometer
{
  class AccelerometerTests
    : public WEIApp::Task
  {
  public:
    bool m_keys;
    /*!
     * @brief Constructor
     */
    AccelerometerTests()
    {
    }
    /*!
     * @brief Destructor
     */
    ~AccelerometerTests()
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

/*
    void test_getDevices()
    {
     WEIApp  std::cout<<"getDevices Test"<<std::endl;
      App::Pressure onewire;
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
*/
    void test_getValue()
    {
      std::cout<<"getValue Test"<<std::endl;
      WEIApp::Accelerometer accelerometer;
      accelerometer.initAccelerometer();

      m_keys = false;
      activate(); 

      std::cout<<"Unit G "<<std::endl;
      /*
      std::cout<< std::setw(12) << "X";
      std::cout<< std::setw(12) << "Y";
      std::cout<< std::setw(12) << "Z"<<std::endl;
      */
      while(!m_keys)
        {  
          std::string str = accelerometer.getValue();
          std::cout<< str  <<std::endl;
          ::sleep(1);
        }      
      finalize();
    }
  };
};
int main(int argc, char* argv[])
{
  std::cout<<"AccelerometerTests"<<std::endl;
  Accelerometer::AccelerometerTests tests;
/*
  tests.test_getDevices();
*/
  tests.test_getValue();
}
#endif // AccelerometerTests_cpp
