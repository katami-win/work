#!/usr/bin/env python
# -*- coding: utf-8 -*-
# -*- Python -*-

"""
 @file GoogleApiRTC.py
 @brief GoogleApi
 @date $Date$


"""
import os 
import sys
import json
import gspread
#from oauth2client.client import SignedJwtAssertionCredentials
from oauth2client.service_account import ServiceAccountCredentials
import datetime
from datetime import datetime as dt
import time
sys.path.append(".")

# Import RTM module
import RTC
import OpenRTM_aist


# Import Service implementation class
# <rtc-template block="service_impl">

# </rtc-template>

# Import Service stub modules
# <rtc-template block="consumer_import">
# </rtc-template>


# This module's spesification
# <rtc-template block="module_spec">
googlapirtc_spec = ["implementation_id", "GoogleApiRTC", 
         "type_name",         "GoogleApiRTC", 
         "description",       "GoogleApi", 
         "version",           "1.0.0", 
         "vendor",            "WIN ELECTRONIC INDUSTRIES", 
         "category",          "Category", 
         "activity_type",     "STATIC", 
         "max_instance",      "1", 
         "language",          "Python", 
         "lang_type",         "SCRIPT",
         ""]
# </rtc-template>

##
# @class GoogleApiRTC
# @brief GoogleApi
# 
# 
class GoogleApiRTC(OpenRTM_aist.DataFlowComponentBase):
    
    ##
    # @brief constructor
    # @param manager Maneger Object
    # 
    def __init__(self, manager):
        OpenRTM_aist.DataFlowComponentBase.__init__(self, manager)

        m_data001_arg = [None] * ((len(RTC._d_TimedString) - 4) / 2)
        self._d_m_data001 = RTC.TimedString(*m_data001_arg)

        m_data002_arg = [None] * ((len(RTC._d_TimedString) - 4) / 2)
        self._d_m_data002 = RTC.TimedString(*m_data002_arg)

        m_data003_arg = [None] * ((len(RTC._d_TimedString) - 4) / 2)
        self._d_m_data003 = RTC.TimedString(*m_data003_arg)

        m_data004_arg = [None] * ((len(RTC._d_TimedString) - 4) / 2)
        self._d_m_data004 = RTC.TimedString(*m_data004_arg)

        m_data005_arg = [None] * ((len(RTC._d_TimedString) - 4) / 2)
        self._d_m_data005 = RTC.TimedString(*m_data005_arg)

        m_data006_arg = [None] * ((len(RTC._d_TimedString) - 4) / 2)
        self._d_m_data006 = RTC.TimedString(*m_data006_arg)

        m_data007_arg = [None] * ((len(RTC._d_TimedString) - 4) / 2)
        self._d_m_data007 = RTC.TimedString(*m_data007_arg)

        m_data008_arg = [None] * ((len(RTC._d_TimedString) - 4) / 2)
        self._d_m_data008 = RTC.TimedString(*m_data008_arg)
        """
        """
        self._data001In = OpenRTM_aist.InPort("data001", self._d_m_data001)
        self._data002In = OpenRTM_aist.InPort("data002", self._d_m_data002)
        self._data003In = OpenRTM_aist.InPort("data003", self._d_m_data003)
        self._data004In = OpenRTM_aist.InPort("data004", self._d_m_data004)
        self._data005In = OpenRTM_aist.InPort("data005", self._d_m_data005)
        self._data006In = OpenRTM_aist.InPort("data006", self._d_m_data006)
        self._data007In = OpenRTM_aist.InPort("data007", self._d_m_data007)
        self._data008In = OpenRTM_aist.InPort("data008", self._d_m_data008)


        m_printdata_arg = [None] * ((len(RTC._d_TimedString) - 4) / 2)
        self._d_m_printdata = RTC.TimedString(*m_printdata_arg)
        """
        """
        self._printdataOut = OpenRTM_aist.OutPort("printdata", self._d_m_printdata)


        


        # initialize of configuration-data.
        # <rtc-template block="init_conf_param">
        
        # </rtc-template>


         
    ##
    #
    # The initialize action (on CREATED->ALIVE transition)
    # formaer rtc_init_entry() 
    # 
    # @return RTC::ReturnCode_t
    # 
    #
    def onInitialize(self):
        # Bind variables and configuration variable
        
        # Set InPort buffers
        self.addInPort("data001",self._data001In)
        self.addInPort("data002",self._data002In)
        self.addInPort("data003",self._data003In)
        self.addInPort("data004",self._data004In)
        self.addInPort("data005",self._data005In)
        self.addInPort("data006",self._data006In)
        self.addInPort("data007",self._data007In)
        self.addInPort("data008",self._data008In)
        
        # Set OutPort buffers
        self.addOutPort("printdata",self._printdataOut)
        
        # Set service provider to Ports
        
        # Set service consumers to Ports
        
        # Set CORBA Service Ports

        self.doc_id =  '1uCOpwYXa1wnCQMWP7tib3Fv5Tf3jQFGT9zEPHVFe60s'

        self.json_path = '_iot-seminar-project-1181b17ee94f.json'
        scope       = ['https://spreadsheets.google.com/feeds']
        credentials =  ServiceAccountCredentials.from_json_keyfile_name(
                       self.json_path,scope)
        gclient = gspread.authorize(credentials)
        gfile   = gclient.open_by_key(self.doc_id)
        #self._wsheet  = gfile.worksheet(os.uname()[1])
        self._wsheet  = gfile.get_worksheet(0)

        self._uploadData = {}
        return RTC.RTC_OK
    
    #    ##
    #    # 
    #    # The finalize action (on ALIVE->END transition)
    #    # formaer rtc_exiting_entry()
    #    # 
    #    # @return RTC::ReturnCode_t
    #
    #    # 
    #def onFinalize(self):
    #
    #    return RTC.RTC_OK
    
    #    ##
    #    #
    #    # The startup action when ExecutionContext startup
    #    # former rtc_starting_entry()
    #    # 
    #    # @param ec_id target ExecutionContext Id
    #    #
    #    # @return RTC::ReturnCode_t
    #    #
    #    #
    #def onStartup(self, ec_id):
    #
    #    return RTC.RTC_OK
    
    #    ##
    #    #
    #    # The shutdown action when ExecutionContext stop
    #    # former rtc_stopping_entry()
    #    #
    #    # @param ec_id target ExecutionContext Id
    #    #
    #    # @return RTC::ReturnCode_t
    #    #
    #    #
    #def onShutdown(self, ec_id):
    #
    #    return RTC.RTC_OK
    
    #    ##
    #    #
    #    # The activated action (Active state entry action)
    #    # former rtc_active_entry()
    #    #
    #    # @param ec_id target ExecutionContext Id
    #    # 
    #    # @return RTC::ReturnCode_t
    #    #
    #    #
    def onActivated(self, ec_id):
        return RTC.RTC_OK
    
    #    ##
    #    #
    #    # The deactivated action (Active state exit action)
    #    # former rtc_active_exit()
    #    #
    #    # @param ec_id target ExecutionContext Id
    #    #
    #    # @return RTC::ReturnCode_t
    #    #
    #    #
    #def onDeactivated(self, ec_id):
    #
    #    return RTC.RTC_OK
    
    #    ##
    #    #
    #    # The execution action that is invoked periodically
    #    # former rtc_active_do()
    #    #
    #    # @param ec_id target ExecutionContext Id
    #    #
    #    # @return RTC::ReturnCode_t
    #    #
    #    #
    def onExecute(self, ec_id):
        flag = 0;
        self._uploadData = {}
        if self._data001In.isNew():
            indata = self._data001In.read()
            arg = indata.data.split(':')
            #print arg
            try:
                self._uploadData[arg[1]] = float(arg[3])
            except:
                self._uploadData[arg[1]] = arg[3]
            flag = 1;
        if self._data002In.isNew():
            indata = self._data002In.read()
            arg = indata.data.split(':')
            #print arg
            try:
                self._uploadData[arg[1]] = float(arg[3])
            except:
                self._uploadData[arg[1]] = arg[3]
            flag = 1;
        if self._data003In.isNew():
            indata = self._data003In.read()
            arg = indata.data.split(':')
            #print(arg)
            try:
                self._uploadData[arg[1]] = float(arg[3])
            except:
                self._uploadData[arg[1]] = arg[3]
            flag = 1;
        if self._data004In.isNew():
            indata = self._data004In.read()
            arg = indata.data.split(':')
            #print arg
            try:
                self._uploadData[arg[1]] = float(arg[3])
            except:
                self._uploadData[arg[1]] = arg[3]
            flag = 1;
        if self._data005In.isNew():
            indata = self._data005In.read()
            arg = indata.data.split(':')
            #print arg
            try:
                self._uploadData[arg[1]] = float(arg[3])
            except:
                self._uploadData[arg[1]] = arg[3]
            flag = 1;
        if self._data006In.isNew():
            indata = self._data006In.read()
            arg = indata.data.split(':')
            #print arg
            try:
                self._uploadData[arg[1]] = float(arg[3])
            except:
                self._uploadData[arg[1]] = arg[3]
            flag = 1;
        if self._data007In.isNew():
            indata = self._data007In.read()
            arg = indata.data.split(':')
            #print arg
            try:
                self._uploadData[arg[1]] = float(arg[3])
            except:
                self._uploadData[arg[1]] = arg[3]
            flag = 1;
        if self._data008In.isNew():
            indata = self._data008In.read()
            arg = indata.data.split(':')
            #print arg
            try:
                self._uploadData[arg[1]] = float(arg[3])
            except:
                self._uploadData[arg[1]] = arg[3]
            flag = 1;
            #print flag
        if flag != 0:
            tdatetime = dt.now()
            data = []
            data.append((tdatetime-datetime.datetime(1899, 12, 30)).days)
            #data.append(tdatetime.strftime('%Y/%m/%d'))
            tdelta = tdatetime - dt.strptime("0:0:0.0", "%H:%M:%S.%f")
            data.append((tdelta.seconds+(tdelta.microseconds/1000000))/(60.0*60.0*24.0))
            #data.append(tdatetime.strftime('%H:%M:%S'))
            
            items = ['Temperature','Humidity','Barometer', 'Accelerometer(x)', 'Accelerometer(y)', 'Accelerometer(z)','Illumination','GPS']
            for key in items:
                if key in self._uploadData:
                    data.append(self._uploadData[key])
                else:
                    data.append('None')
            try :
                print(data)
                self._wsheet.append_row(data)
            except :
                print("Refresh the access token")
                #doc_id =  '1uCOpwYXa1wnCQMWP7tib3Fv5Tf3jQFGT9zEPHVFe60s'
                #json_path = '_iot-seminar-project-1181b17ee94f.json'
                scope       = ['https://spreadsheets.google.com/feeds']
                credentials =  ServiceAccountCredentials.from_json_keyfile_name(
                               self.json_path,scope)
                gclient = gspread.authorize(credentials)
                gfile   = gclient.open_by_key(self.doc_id)
                self._wsheet  = gfile.get_worksheet(0)
                self._wsheet.append_row(data)

            flag = 0;
        return RTC.RTC_OK
    
    #    ##
    #    #
    #    # The aborting action when main logic error occurred.
    #    # former rtc_aborting_entry()
    #    #
    #    # @param ec_id target ExecutionContext Id
    #    #
    #    # @return RTC::ReturnCode_t
    #    #
    #    #
    #def onAborting(self, ec_id):
    #
    #    return RTC.RTC_OK
    
    #    ##
    #    #
    #    # The error action in ERROR state
    #    # former rtc_error_do()
    #    #
    #    # @param ec_id target ExecutionContext Id
    #    #
    #    # @return RTC::ReturnCode_t
    #    #
    #    #
    #def onError(self, ec_id):
    #
    #    return RTC.RTC_OK
    
    #    ##
    #    #
    #    # The reset action that is invoked resetting
    #    # This is same but different the former rtc_init_entry()
    #    #
    #    # @param ec_id target ExecutionContext Id
    #    #
    #    # @return RTC::ReturnCode_t
    #    #
    #    #
    #def onReset(self, ec_id):
    #
    #    return RTC.RTC_OK
    
    #    ##
    #    #
    #    # The state update action that is invoked after onExecute() action
    #    # no corresponding operation exists in OpenRTm-aist-0.2.0
    #    #
    #    # @param ec_id target ExecutionContext Id
    #    #
    #    # @return RTC::ReturnCode_t
    #    #

    #    #
    #def onStateUpdate(self, ec_id):
    #
    #    return RTC.RTC_OK
    
    #    ##
    #    #
    #    # The action that is invoked when execution context's rate is changed
    #    # no corresponding operation exists in OpenRTm-aist-0.2.0
    #    #
    #    # @param ec_id target ExecutionContext Id
    #    #
    #    # @return RTC::ReturnCode_t
    #    #
    #    #
    #def onRateChanged(self, ec_id):
    #
    #    return RTC.RTC_OK
    



def GoogleApiRTCInit(manager):
    profile = OpenRTM_aist.Properties(defaults_str=googlapirtc_spec)
    manager.registerFactory(profile,
                            GoogleApiRTC,
                            OpenRTM_aist.Delete)

def MyModuleInit(manager):
    GoogleApiRTCInit(manager)

    # Create a component
    comp = manager.createComponent("GoogleApiRTC")

def main():
    mgr = OpenRTM_aist.Manager.init(sys.argv)
    mgr.setModuleInitProc(MyModuleInit)
    mgr.activateManager()
    mgr.runManager()

if __name__ == "__main__":
    main()

