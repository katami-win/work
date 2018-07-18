// -*- C++ -*-
/*!
 * @file   UartTests.cpp
 * @brief  Uart test class
 * @date   $Date:$
 *
 * $Id: UartTests.cpp 183 2014-06-17 01:15:21Z pi $
 *
 */

/*
 * $Log: $
 */

#ifndef UartTests_cpp
#define UartTests_cpp

#include <iostream> 
#include <stdlib.h>
#include <time.h>

#include <Uart.h> 
//#include <Split.h> 

/*!
 * @class UartTests class
 * @brief Uart test
 */
namespace Uart
{
  class UartTests
  {
  public:
    /*!
     * @brief Constructor
     */
    UartTests()
    {
    }
    /*!
     * @brief Destructor
     */
    ~UartTests()
    {
      
    }
    /*!
     * 
     */
    void test_test1()
    {
      WEIApp::Uart uart;
      uart.initUart();
      uart.shutdownUart();

    }
    /*!
     * 
     */
    void test_test2()
    {
      WEIApp::Uart uart;
      if(uart.initUart())
        {
          while(1)
            {
              for(int ic=0;ic<7;++ic)
                {
                  std::string str = uart.readGPGGA();
                  if (str.size() != 0) 
                    {
                      std::cout<<str<<std::endl;
                    }
                }
            }
        }
      uart.shutdownUart();
    }
  };
};
int main(int argc, char* argv[])
{
  std::cout<<"UartTests"<<std::endl;
  Uart::UartTests tests;
  //std::cout<<"test_test1()"<<std::endl;
  //tests.test_test1();
  //std::cout<<"test_test2()"<<std::endl;
  tests.test_test2();
}
#endif // UartTests_cpp
