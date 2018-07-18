// -*- C++ -*-
/*!
 * @file  AccelerometerRTC.cpp
 * @brief Accelerometer
 * @date $Date$
 *
 * $Id$
 */

#include <vector>
#include <coil/stringutil.h>
#include "AccelerometerRTC.h"
#include "GetDatetimeString.h"

// Module specification
// <rtc-template block="module_spec">
static const char* accelerometerrtc_spec[] =
  {
    "implementation_id", "AccelerometerRTC",
    "type_name",         "AccelerometerRTC",
    "description",       "Accelerometer",
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
AccelerometerRTC::AccelerometerRTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_xAxisOut("xAxis", m_xAxis),
    m_yAxisOut("yAxis", m_yAxis),
    m_zAxisOut("zAxis", m_zAxis)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
AccelerometerRTC::~AccelerometerRTC()
{
}



RTC::ReturnCode_t AccelerometerRTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("xAxis", m_xAxisOut);
  addOutPort("yAxis", m_yAxisOut);
  addOutPort("zAxis", m_zAxisOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  m_accelerometer.initAccelerometer();
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t AccelerometerRTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AccelerometerRTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AccelerometerRTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AccelerometerRTC::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AccelerometerRTC::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t AccelerometerRTC::onExecute(RTC::UniqueId ec_id)
{
  struct utsname systeminfo;
  ::uname(&systeminfo);
  std::stringstream stringBuffer;
  std::string str = m_accelerometer.getValue();
  std::vector<std::string> vmap = coil::split(str,",",false);
  
   
  stringBuffer.str("");
  stringBuffer<<systeminfo.nodename<<":"<<"Accelerometer(x)"<<":"
    << WEIApp::getDatetimeString()<<":"
    << vmap.at(0);
    //<< vmap.at(0)<<std::endl;
  m_xAxis.data = CORBA::string_dup(stringBuffer.str().c_str());
  m_xAxisOut.write();

  stringBuffer.str("");
  stringBuffer<<systeminfo.nodename<<":"<<"Accelerometer(y)"<<":"
    << WEIApp::getDatetimeString()<<":"
    << vmap.at(1);
    //<< vmap.at(1)<<std::endl;
  m_yAxis.data = CORBA::string_dup(stringBuffer.str().c_str());
  m_yAxisOut.write();

  stringBuffer.str("");
  stringBuffer<<systeminfo.nodename<<":"<<"Accelerometer(z)"<<":"
    << WEIApp::getDatetimeString()<<":"
    << vmap.at(2);
    //<< vmap.at(2)<<std::endl;
  m_zAxis.data = CORBA::string_dup(stringBuffer.str().c_str());
  m_zAxisOut.write();
  return RTC::RTC_OK;
}


/*
RTC::ReturnCode_t AccelerometerRTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AccelerometerRTC::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AccelerometerRTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AccelerometerRTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AccelerometerRTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void AccelerometerRTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(accelerometerrtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<AccelerometerRTC>,
                             RTC::Delete<AccelerometerRTC>);
  }
  
};


