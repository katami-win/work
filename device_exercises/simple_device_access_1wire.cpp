#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include <dirent.h>

int main(int argc, char* argv[])
{
    //DIR* dir_ptr(::opendir("/sys/bus/w1/devices/"));
    DIR* dir_ptr(::opendir(set Virtual directory));

    std::vector<std::string> flist;
    struct dirent* ent;
    while ((ent = ::readdir(dir_ptr)) != 0)
      {
        std::string fname(ent->d_name);
        //std::cout<<fname<<std::endl;
        if((fname.compare("w1_bus_master1") == 0)|| 
            (fname.compare(".") == 0) ||
            (fname.compare("..") == 0) )
          {
          }
        else
          { 
            flist.push_back(ent->d_name); 
          }

      }
    ::closedir(dir_ptr);

    std::vector<std::string>::iterator it(flist.begin());
    while (it != flist.end())
      {
        std::string str_dir("/sys/bus/w1/devices/");
        str_dir = str_dir + *it + "/w1_slave";
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
                std::cout<<value<<std::endl;;
                break;
              }
            
          }
          ++it;
      }
}

