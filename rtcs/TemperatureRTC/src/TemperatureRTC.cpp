// -*- C++ -*-
/*!
 * @file  TemperatureRTC.cpp
 * @brief Temperature
 * @date $Date$
 *
 * $Id$
 */

#include "TemperatureRTC.h"
#include "GetDatetimeString.h"

// Module specification
// <rtc-template block="module_spec">
static const char* temperaturertc_spec[] =
  {
    "implementation_id", "TemperatureRTC",
    "type_name",         "TemperatureRTC",
    "description",       "Temperature",
    "version",           "1.0.0",
    "vendor",            "WIN ELECTRONIC INDUSTRIES",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
TemperatureRTC::TemperatureRTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_temperatureOut("temperature", m_temperature)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
TemperatureRTC::~TemperatureRTC()
{
}



RTC::ReturnCode_t TemperatureRTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("temperature", m_temperatureOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t TemperatureRTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TemperatureRTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TemperatureRTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


/*
RTC::ReturnCode_t TemperatureRTC::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


/*
RTC::ReturnCode_t TemperatureRTC::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t TemperatureRTC::onExecute(RTC::UniqueId ec_id)
{
  struct utsname systeminfo;
  ::uname(&systeminfo);
  std::stringstream stringBuffer;
  stringBuffer.str("");

  std::vector<std::string> devies = m_onewire.getDevices();
  float val(0.0);
  if(!devies.empty())
    {
      std::vector<std::string>::iterator it(devies.begin());
      while (it != devies.end())
        {
          val = m_onewire.getValue(*it);
          ++it;
        }
    }
  else
    {
      std::cout<<"error."<<std::endl;
      std::cout<<"Devices are non-connection."<<std::endl;
    }

  stringBuffer<<systeminfo.nodename<<":"<<"Temperature"<<":"
    << WEIApp::getDatetimeString()<<":"
    << val ;
    //<< val <<std::endl;
  m_temperature.data = CORBA::string_dup(stringBuffer.str().c_str());
  m_temperatureOut.write();
  return RTC::RTC_OK;
}


/*
RTC::ReturnCode_t TemperatureRTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TemperatureRTC::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TemperatureRTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TemperatureRTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TemperatureRTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void TemperatureRTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(temperaturertc_spec);
    manager->registerFactory(profile,
                             RTC::Create<TemperatureRTC>,
                             RTC::Delete<TemperatureRTC>);
  }
  
};


