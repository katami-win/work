// -*- C++ -*-
/*!
 * @file  BarometerRTC.cpp
 * @brief Barometer
 * @date $Date$
 *
 * $Id$
 */

#include <sstream>

#include <unistd.h>

#include "BarometerRTC.h"
#include "GetDatetimeString.h"

// Module specification
// <rtc-template block="module_spec">
static const char* barometerrtc_spec[] =
  {
    "implementation_id", "BarometerRTC",
    "type_name",         "BarometerRTC",
    "description",       "Barometer",
    "version",           "1.0.0",
    "vendor",            "VenderName",
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
BarometerRTC::BarometerRTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_pressureOut("pressure", m_pressure)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
BarometerRTC::~BarometerRTC()
{
}



RTC::ReturnCode_t BarometerRTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("pressure", m_pressureOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>

  m_barometer.initPressure();
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t BarometerRTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t BarometerRTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t BarometerRTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t BarometerRTC::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t BarometerRTC::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

RTC::ReturnCode_t BarometerRTC::onExecute(RTC::UniqueId ec_id)
{
  struct utsname systeminfo;
  ::uname(&systeminfo);
  //std::cout<<systeminfo.nodename<<std::endl;
  std::stringstream stringBuffer;
  stringBuffer.str("");
  stringBuffer<<systeminfo.nodename<<":"<<"Barometer"<<":"
    << WEIApp::getDatetimeString()<<":"
    << m_barometer.getValue();
    //<< m_barometer.getValue()<<std::endl;
  m_pressure.data = CORBA::string_dup(stringBuffer.str().c_str());
  m_pressureOut.write();
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t BarometerRTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t BarometerRTC::onError(RTC::UniqueId ec_id)
{

  return RTC::RTC_OK;
}
*/


/*
RTC::ReturnCode_t BarometerRTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t BarometerRTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t BarometerRTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void BarometerRTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(barometerrtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<BarometerRTC>,
                             RTC::Delete<BarometerRTC>);
  }
  
};


