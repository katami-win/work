// -*- C++ -*-
/*!
 * @file  HumidityRTC.cpp
 * @brief Humidity
 * @date $Date$
 *
 * $Id$
 */

#include <vector>
#include <coil/stringutil.h>
#include "HumidityRTC.h"
#include "GetDatetimeString.h"

// Module specification
// <rtc-template block="module_spec">
static const char* humidityrtc_spec[] =
  {
    "implementation_id", "HumidityRTC",
    "type_name",         "HumidityRTC",
    "description",       "Humidity",
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
HumidityRTC::HumidityRTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_humidityOut("humidity", m_humidity)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
HumidityRTC::~HumidityRTC()
{
}



RTC::ReturnCode_t HumidityRTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("humidity", m_humidityOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  m_hygrometer.initHumidityTemperature();
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t HumidityRTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t HumidityRTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t HumidityRTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t HumidityRTC::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t HumidityRTC::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t HumidityRTC::onExecute(RTC::UniqueId ec_id)
{
  struct utsname systeminfo;
  ::uname(&systeminfo);
  std::stringstream stringBuffer;
  stringBuffer.str("");
  std::string str = m_hygrometer.getValue();
  std::vector<std::string> vmap = coil::split(str,",",false);

  stringBuffer<<systeminfo.nodename<<":"<<"Humidity"<<":"
    << WEIApp::getDatetimeString()<<":"
    << vmap.at(1);
    //<< vmap.at(1)<<std::endl;
  m_humidity.data = CORBA::string_dup(stringBuffer.str().c_str());
  m_humidityOut.write();
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t HumidityRTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t HumidityRTC::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t HumidityRTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t HumidityRTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t HumidityRTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void HumidityRTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(humidityrtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<HumidityRTC>,
                             RTC::Delete<HumidityRTC>);
  }
  
};


