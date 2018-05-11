#!/usr/bin/env python
# -*- coding: euc-jp -*- 


##
# @file simple_device_access_acc_org.py
# @brief 

import io
import fcntl
import time
import struct

def main():

  I2C_SLAVE =      0x0703

  rp = io.open("/dev/i2c-1", mode="rb", buffering=0);
  wp = io.open("/dev/i2c-1", mode="wb", buffering=0);

  fcntl.ioctl(rp, I2C_SLAVE, 0x1d)
  fcntl.ioctl(wp, I2C_SLAVE, 0x1d)

  time.sleep(0.1);

  #POWER_CTL
  buf = bytearray() 
  buf.append(0x2d)
  buf.append(0x08)
  wp.write(buf);

  #DATA_FORMAT
  buf = bytearray() 
  buf.append(0x31)
  buf.append(0x0b)
  wp.write(buf);

  wp.write(bytearray([0x32]));
  data = rp.read(6);

  x_val = struct.unpack('<h', bytes(data[0:2]))[0]
  y_val = struct.unpack('<h', bytes(data[2:4]))[0]
  z_val = struct.unpack('<h', bytes(data[4:6]))[0]

  print(str(float(x_val)*0.0039) + "," + str(float(y_val)*0.0039) + "," + str(float(z_val)*0.0039))


  rp.close()
  wp.close()


    



if __name__ == '__main__':
  main()
