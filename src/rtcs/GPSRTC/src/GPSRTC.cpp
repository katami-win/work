// -*- C++ -*-
/*!
 * @file  GPSRTC.cpp
 * @brief GPS
 * @date $Date$
 *
 * $Id$
 */

#include "GPSRTC.h"
#include "GetDatetimeString.h"

// Module specification
// <rtc-template block="module_spec">
static const char* gpsrtc_spec[] =
  {
    "implementation_id", "GPSRTC",
    "type_name",         "GPSRTC",
    "description",       "GPS",
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
GPSRTC::GPSRTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_GPGGAOut("GPGGA", m_GPGGA)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
GPSRTC::~GPSRTC()
{
}



RTC::ReturnCode_t GPSRTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("GPGGA", m_GPGGAOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  m_gps.initUart();
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t GPSRTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t GPSRTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t GPSRTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t GPSRTC::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t GPSRTC::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t GPSRTC::onExecute(RTC::UniqueId ec_id)
{
  struct utsname systeminfo;
  ::uname(&systeminfo);
  std::stringstream stringBuffer;
  stringBuffer.str("");

  std::string str("");
  for(int ic=0;ic<7;++ic)
   {
      str = m_gps.readGPGGA();
      if (str.empty())
        {
          break;
        }
      std::string::size_type found_pos(0); 
      found_pos = str.find("GPGGA", 0);
      if(found_pos != std::string::npos)
        {
          break;
        }
    }
  std::string::size_type pos(0); 
  pos = str.find("\r\n", 0);
  if(pos != std::string::npos)
    {
std::cout<<pos<<std::endl;
      str.replace(pos, 2, "");
    }
  stringBuffer<<systeminfo.nodename<<":"<<"GPS"<<":"
    << WEIApp::getDatetimeString()<<":"
    << str;
    //<< str <<std::endl;
  m_GPGGA.data = CORBA::string_dup(stringBuffer.str().c_str());
  m_GPGGAOut.write();
  return RTC::RTC_OK;
}


/*
RTC::ReturnCode_t GPSRTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t GPSRTC::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t GPSRTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t GPSRTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t GPSRTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void GPSRTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(gpsrtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<GPSRTC>,
                             RTC::Delete<GPSRTC>);
  }
  
};


