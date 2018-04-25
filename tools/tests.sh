#!/bin/bash
PS3="please select item > "

#
select item in "switch" "illumination" "accelerometer" "humidityTemperature" "gps" "adc" "lcd" "buzzer" "photocoupler" "serial" "dout" "quit"
do
    if [ "${REPLY}" = "q" ]; then
        echo "Exit from system."
        exit 0
    fi
    if [ -z "$item" ] ; then
        continue
    fi
    case "$item" in
        quit ) echo "Exit from system."
           break ;;
        switch ) echo "Switch"
           sudo ~/work/ons_tests/src/tests/Gpio/build/GpioTests;;
        illumination ) echo "Illumination"
           sudo ~/work/ons_tests/src/tests/Illumination/build/IlluminationTests;;
        accelerometer ) echo "Accelerometer"
           sudo ~/work/ons_tests/src/tests/Accelerometer/build/AccelerometerTests;;
        humidityTemperature ) echo "HumidityTemperature"
           sudo ~/work/ons_tests/src/tests/HumidityTemperature/build/HumidityTemperatureTests;;
        gps ) echo "GPS"
           sudo ~/work/ons_tests/src/tests/Uart/build/UartTests;;
        adc ) echo "LCD"
           sudo ~/work/tests/adc_testc;;
        lcd ) echo "LCD"
           sudo ~/work/ons_tests/src/tests/Clcd/build/ClcdTests;;
        buzzer ) echo "Buzzer"
           sudo ~/work/ons_tests/src/tests/Gpio2/build/GpioTests;;
        photocoupler ) echo "Photocoupler"
           sudo ~/work/ons_tests/src/tests/Gpio3/build/GpioTests;;
        serial ) echo "Serial"
           sudo python ~/work/tests/serial_test.py;;
        dout ) echo "DOUT"
           sudo ~/work/ons_tests/src/tests/Gpio4/build/GpioTests;;
        * ) echo "you select $item ($REPLY)";;
    esac
done
