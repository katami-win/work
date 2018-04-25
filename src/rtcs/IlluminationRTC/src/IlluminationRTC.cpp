// -*- C++ -*-
/*!
 * @file  IlluminationRTC.cpp
 * @brief Illumination
 * @date $Date$
 *
 * $Id$
 */

#include "IlluminationRTC.h"
#include "GetDatetimeString.h"

// Module specification
// <rtc-template block="module_spec">
static const char* illuminationrtc_spec[] =
  {
    "implementation_id", "IlluminationRTC",
    "type_name",         "IlluminationRTC",
    "description",       "Illumination",
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
IlluminationRTC::IlluminationRTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_luxOut("lux", m_lux)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
IlluminationRTC::~IlluminationRTC()
{
}



RTC::ReturnCode_t IlluminationRTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("lux", m_luxOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>

  m_illumination.initIllumination();
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t IlluminationRTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IlluminationRTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IlluminationRTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t IlluminationRTC::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t IlluminationRTC::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t IlluminationRTC::onExecute(RTC::UniqueId ec_id)
{
  struct utsname systeminfo;
  ::uname(&systeminfo);
  std::stringstream stringBuffer;
  stringBuffer.str("");
  m_illumination.setGain(0);
  stringBuffer<<systeminfo.nodename<<":"<<"Illumination"<<":"
    << WEIApp::getDatetimeString()<<":"
    << m_illumination.getValue();
    //<< m_illumination.getValue()<<std::endl;
  m_lux.data = CORBA::string_dup(stringBuffer.str().c_str());
  m_luxOut.write();

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t IlluminationRTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IlluminationRTC::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IlluminationRTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IlluminationRTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t IlluminationRTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void IlluminationRTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(illuminationrtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<IlluminationRTC>,
                             RTC::Delete<IlluminationRTC>);
  }
  
};


