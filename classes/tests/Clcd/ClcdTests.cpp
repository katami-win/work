// -*- C++ -*-
/*!
 * @file   ClcdTests.cpp
 * @brief  Clcd test class
 * @date   $Date: 
 *
 * $Id: ClcdTests.cpp 183 2014-06-17 01:15:21Z pi $
 *
 */

/*
 * $Log: $
 */

#ifndef ClcdTests_cpp
#define ClcdTests_cpp

#include <iostream> 
#include <Clcd.h> 

/*!
 * @class ClcdTests class
 * @brief Clcd test
 */
namespace Clcd
{
  class ClcdTests
  {
  public:
    /*!
     * @brief Constructor
     */
    ClcdTests()
    {
    }
    /*!
     * @brief Destructor
     */
    ~ClcdTests()
    {
      
    }
    /*!
     * 
     */
    void test_test1()
    {
      WEIApp::Clcd clcd;
      clcd.initClcd();
      clcd.shutdownClcd();

    }
    /*!
     * 
     */
    void test_test2()
    {
      WEIApp::Clcd clcd;
      if(clcd.initClcd())
      {
        clcd.printString(0,"01234567");
        clcd.printString(1,"ABCDEFGH");
      }
      clcd.shutdownClcd();
    }
    /*!
     * 
     */
/*
    void test_test3()
    {
      WEIApp::Clcd clcd;
      if(clcd.initClcd())
      {
        clcd.activate();
        clcd.printStringiAutomaticErasure("01234567",3);
        clcd.printString(1,"12345");
        sleep(1);
        clcd.printStringiAutomaticErasure("ABCDEFGH",3);
        sleep(1);
        clcd.printStringiAutomaticErasure("abcdefgh",3);
        sleep(1);
        clcd.printStringiAutomaticErasure("Check 3s",3);
        sleep(5);
        clcd.printStringiAutomaticErasure("abcdefgh",3);
        sleep(1);
        clcd.printStringiAutomaticErasure("Check 4s",4);
        sleep(6);
      }
      clcd.shutdownClcd();
    }
*/
    /*!
     * 
     */
/*
    void test_test4()
    {
      WEIApp::Clcd clcd;
      long utime;
      if(clcd.initClcd())
      {
        utime=900000;
        clcd.activate();
        clcd.printString(1,"991234");
        for(;;)
          {
            std::cout<<utime<<std::endl;
            clcd.printStringiAutomaticErasure("12",1);
            usleep(utime);
            utime = utime + 10000;
            if(utime>1100000)
              {
                utime=900000;
              }
          }
      }
      clcd.shutdownClcd();
    }
*/
    /*!
     * 
     */
/*
    void test_test5()
    {
      WEIApp::Clcd clcd;
      long utime;
      if(clcd.initClcd())
        {
          WEIApp::Gpio gpio;
          if(!gpio.initGpio())
            {
              clcd.printString(0,"E:gpio");
              return ;  //Initial processing failed
            }
          utime=800000;
          clcd.activate();
          clcd.printString(1,"991234");
          int ic(0);
          for(;;)
            {
              //std::cout<<utime<<std::endl;
              clcd.printStringiAutomaticErasure("12",1);
              usleep(utime);
              utime = utime + 10000;
              if(utime>1200000)
                {
                  utime=800000;
                }
              if(ic & 0x0001)
                {
                  gpio.onLed();
                }
              else
                {
                  gpio.offLed();
                }
              ++ic;
              clcd.printString(1,"991234");
            }
        }
      clcd.shutdownClcd();
    }
*/
  };
};
int main(int argc, char* argv[])
{
  std::cout<<"ClcdTests"<<std::endl;
  Clcd::ClcdTests tests;
  std::cout<<"test_test1()"<<std::endl;
  tests.test_test1();
  std::cout<<"test_test2()"<<std::endl;
  tests.test_test2();
  /*
  std::cout<<"test_test3()"<<std::endl;
  tests.test_test3();
  */
  //std::cout<<"test_test4()"<<std::endl;
  //tests.test_test4();
  //std::cout<<"test_test5()"<<std::endl;
  //tests.test_test5();
}
#endif // ClcdTests_cpp
