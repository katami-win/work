// -*- C++ -*-
/*!
 * @file OneWire.cpp
 * @brief Controls 1-wire.
 * @date $Date: $
 *
 * $Id: $
 *
 */

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include <dirent.h>

#include <OneWire.h>


namespace WEIApp
{

  /*!
   * @brief Constructor
   * @param none
   */
  OneWire::OneWire()
  {
  }
  /*!
   * @brief Destructor
   * @param none
   */
  OneWire::~OneWire(void)
  {
  }
  /*!
   * @brief OneWire initialization
   * @return true: Success
   *         false:Failure
   */
  bool OneWire::initOneWire()
  {
    return true;

  }
  /*!
   * @brief Shutdown OneWire
   * 
   */
  void OneWire::shutdownOneWire()
  {
  }

  /*!
   * @brief Gets the price of the device of an argument.
   * @param str device
   * 
   */
  float OneWire::getValue(std::string str)
  {
    struct dirent* ent; 
    std::vector<std::string> flist;
    DIR* dir_ptr(::opendir("/sys/bus/w1/devices/"));
    if (dir_ptr == 0) 
      { 
        ::closedir(dir_ptr);
        return 0.0;
      }
    while ((ent = ::readdir(dir_ptr)) != 0)
      {
        std::string fname(ent->d_name);
        if((fname.compare(str) == 0))
          {
            std::string str_dir("/sys/bus/w1/devices/");
            str_dir = str_dir + fname + "/w1_slave";
            std::ifstream ifs( str_dir.c_str() );
            std::string line_str;
            std::string::size_type pos(0);
            while (getline(ifs, line_str))
              {
                pos = line_str.find("t=");
                if(pos != std::string::npos)
                  {
                    std::string value_str = line_str.substr(pos+2);
                    std::stringstream ss(value_str);
                    float value;
                    ss >> value;
                    value = value / 1000.0;
                    ::closedir(dir_ptr);
                    return value;
                  }
                
              }

          }
      }
    ::closedir(dir_ptr);
    return 0.0;
  
  }

  /*!
   * @brief Gets a list of devices.
   * @param none
   * 
   */
  std::vector<std::string> OneWire::getDevices()
  {
    struct dirent* ent; 
    std::vector<std::string> flist;
    DIR* dir_ptr(::opendir("/sys/bus/w1/devices/"));
    if (dir_ptr == 0) 
      { 
        ::closedir(dir_ptr);
        return flist; 
      }
    while ((ent = ::readdir(dir_ptr)) != 0)
      {
        std::string fname(ent->d_name);
        if((fname.compare("w1_bus_master1") == 0)|| 
            (fname.compare(".") == 0) ||
            (fname.compare("..") == 0) ||
            ((int)fname.rfind("28-") != 0))
          {
          }
        else
          { 
            flist.push_back(ent->d_name); 
          }

      }
    ::closedir(dir_ptr);
    return flist;
  }

}; // namespace 

