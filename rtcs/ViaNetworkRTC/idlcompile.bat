echo off
setlocal
for %%I in (python.exe) do if exist %%~$path:I set f=%%~$path:I
if exist %f% do (
  %f:python.exe=%omniidl.exe -bpython -I"%RTM_ROOT%rtm\idl" -I"/usr/include/openrtm-1.1/rtm/idl/device_interfaces" -I"/usr/include/openrtm-1.1/rtm/idl" idl/BasicDataType.idl idl/BasicDataType.idl 
) else do (
  echo "python.exe" can not be found.
  echo Please modify PATH environmental variable for python command.
)
endlocal
