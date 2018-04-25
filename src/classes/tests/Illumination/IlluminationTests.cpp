// -*- C++ -*-
/*!
 * @file   IlluminationTests.cpp
 * @brief  Illumination test class
 * @date   $Date: $
 *
 * $Id: $
 *
 */

/*
 * $Log: $
 */

#ifndef IlluminationTests_cpp
#define IlluminationTests_cpp

#include <iostream>
#include <iomanip>

#include "Illumination.h"
#include "Task.h" 

/*!
 * @class IlluminationTests class
 * @brief Illumination test
 */
namespace Illumination
{
  class IlluminationTests
    : public WEIApp::Task
  {
  public:
    bool m_keys;
    /*!
     * @brief Constructor
     */
    IlluminationTests()
    {
    }
    /*!
     * @brief Destructor
     */
    ~IlluminationTests()
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
      WEIApp::Illumination illumination;
      illumination.initIllumination();
      
      m_keys = false;
      activate(); 

      std::cout<< std::setw(12) << "High Gain";
      std::cout<< std::setw(12) << "Low Gain";
      std::cout<< std::setw(12) << "Auto Gain"<<std::endl;
      while(!m_keys)
        {  

          illumination.setGain(16);
          //std::cout<< std::setw(8) << std::setfill(' ')<<illumination.getValue();
          std::cout<< std::setw(12) << illumination.getValue()<<std::flush;;

          illumination.setGain(1);
          std::cout<< std::setw(12) << illumination.getValue()<<std::flush;;

          illumination.setGain(0);
          std::cout<< std::setw(12) << illumination.getValue()<<std::flush;;

          //std::cout<<std::flush;
          //std::cout<<"A\r";
          std::cout<<std::endl;
        }
      finalize();
    }
  };
};
int main(int argc, char* argv[])
{
  std::cout<<"IlluminationTests"<<std::endl;
  Illumination::IlluminationTests tests;
  tests.test_getValue();
}
#endif // IlluminationTests_cpp
