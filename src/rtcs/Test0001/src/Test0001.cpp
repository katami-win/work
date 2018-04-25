// -*- C++ -*-
/*!
 * @file  Test0001.cpp
 * @brief test
 * @date $Date$
 *
 * $Id$
 */

#include "Test0001.h"

// Module specification
// <rtc-template block="module_spec">
static const char* test0001_spec[] =
  {
    "implementation_id", "Test0001",
    "type_name",         "Test0001",
    "description",       "test",
    "version",           "1.0.0",
    "vendor",            "katami",
    "category",          "Testin",
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
Test0001::Test0001(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_in1In("in1", m_in1),
    m_out1Out("out1", m_out1)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
Test0001::~Test0001()
{
}



RTC::ReturnCode_t Test0001::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("in1", m_in1In);
  
  // Set OutPort buffer
  addOutPort("out1", m_out1Out);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Test0001::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Test0001::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Test0001::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t Test0001::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Test0001::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t Test0001::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Test0001::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Test0001::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Test0001::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Test0001::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Test0001::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void Test0001Init(RTC::Manager* manager)
  {
    coil::Properties profile(test0001_spec);
    manager->registerFactory(profile,
                             RTC::Create<Test0001>,
                             RTC::Delete<Test0001>);
  }
  
};


