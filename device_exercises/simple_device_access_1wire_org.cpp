#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

#include <dirent.h>

int main(int argc, char* argv[])
{
    std::string str_dir("/sys/bus/w1/devices/28-0000086d92fa/w1_slave");
    std::cout<<str_dir<<std::endl;;
    std::ifstream ifs( str_dir.c_str() );
    std::string line_str;
    std::string::size_type pos(0);
    while (getline(ifs, line_str))
      {
        pos = line_str.find("t=");
        if(pos != std::string::npos)
          {
            std::string value_str = line_str.substr(pos+2);
            std::stringstream ss(value_str);
            float value;
            ss >> value;
            value = value / 1000.0;
            std::cout <<std::fixed<<std::setprecision(3)<< value << "C "<<std::endl;
            break;
          }
        
      }
}


