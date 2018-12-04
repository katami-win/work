#!/bin/bash
cd /home/pi/work/tools
rtm-naming
/home/pi/work/rtcs/AccelerometerRTC/bin/AccelerometerRTCComp &
/home/pi/work/rtcs/BarometerRTC/bin/BarometerRTCComp -f /home/pi/work/rtcs/GPSRTC/bin/rtc.conf &
/home/pi/work/rtcs/GPSRTC/bin/GPSRTCComp -f /home/pi/work/rtcs/GPSRTC/bin/rtc.conf &
/home/pi/work/rtcs/HumidityRTC/bin/HumidityRTCComp &
/home/pi/work/rtcs/IlluminationRTC/bin/IlluminationRTCComp &
/home/pi/work/rtcs/TemperatureRTC/bin/TemperatureRTCComp &
cd /home/pi/work/rtcs/GoogleApiRTC/
python GoogleApiRTC.py &
cd /home/pi/work/tools

sleep 5

rtcon localhost/zerounit.host_cxt/AccelerometerRTC0.rtc:xAxis localhost/zerounit.host_cxt/GoogleApiRTC0.rtc:data001
rtcon localhost/zerounit.host_cxt/AccelerometerRTC0.rtc:yAxis localhost/zerounit.host_cxt/GoogleApiRTC0.rtc:data002
rtcon localhost/zerounit.host_cxt/AccelerometerRTC0.rtc:zAxis localhost/zerounit.host_cxt/GoogleApiRTC0.rtc:data003

rtcon localhost/zerounit.host_cxt/BarometerRTC0.rtc:pressure localhost/zerounit.host_cxt/GoogleApiRTC0.rtc:data004

rtcon localhost/zerounit.host_cxt/GPSRTC0.rtc:GPGGA localhost/zerounit.host_cxt/GoogleApiRTC0.rtc:data005

rtcon localhost/zerounit.host_cxt/HumidityRTC0.rtc:humidity localhost/zerounit.host_cxt/GoogleApiRTC0.rtc:data006

rtcon localhost/zerounit.host_cxt/IlluminationRTC0.rtc:lux localhost/zerounit.host_cxt/GoogleApiRTC0.rtc:data007

rtcon localhost/zerounit.host_cxt/TemperatureRTC0.rtc:temperature localhost/zerounit.host_cxt/GoogleApiRTC0.rtc:data008

rtact localhost/zerounit.host_cxt/AccelerometerRTC0.rtc
rtact localhost/zerounit.host_cxt/BarometerRTC0.rtc
rtact localhost/zerounit.host_cxt/GPSRTC0.rtc
rtact localhost/zerounit.host_cxt/HumidityRTC0.rtc
rtact localhost/zerounit.host_cxt/IlluminationRTC0.rtc
rtact localhost/zerounit.host_cxt/TemperatureRTC0.rtc
rtact localhost/zerounit.host_cxt/GoogleApiRTC0.rtc

sleep 12


rtexit localhost/zerounit.host_cxt/AccelerometerRTC0.rtc
rtexit localhost/zerounit.host_cxt/BarometerRTC0.rtc
rtexit localhost/zerounit.host_cxt/GPSRTC0.rtc
rtexit localhost/zerounit.host_cxt/HumidityRTC0.rtc
rtexit localhost/zerounit.host_cxt/IlluminationRTC0.rtc
rtexit localhost/zerounit.host_cxt/TemperatureRTC0.rtc
rtexit localhost/zerounit.host_cxt/GoogleApiRTC0.rtc

