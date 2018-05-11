#!/usr/bin/env python
# -*- coding: euc-jp -*- 


##
# @file simple_device_access_1wire_org.py
# @brief 

import os

def main():

  directories = os.listdir("/sys/bus/w1/devices/")

  for directory in directories:
    if directory == "w1_bus_master1":
      continue
    wire_name = "/sys/bus/w1/devices/"+directory+"/w1_slave"
    fd = open(wire_name,"r")
    lines = fd.readlines()
    fd.close()
    text = lines[1].strip()
    vstr = text.split("t=")
    if len(vstr) == 1:
      continue
    
    temp = float(vstr[1])
    temp = temp/1000.0

    print(wire_name+" : "+str(temp))
    



if __name__ == '__main__':
  main()
