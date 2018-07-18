// -*- C++ -*-
/*!
 * @file GetDatetimeString.cpp
 * @brief
 * @date $Date: $
 *
 
 * $Id: $
 *
 */

#include <sys/time.h>

#include <sstream>
#include <iostream>


#include "GetDatetimeString.h"


namespace WEIApp
{

/*!
 * @if jp
 * @brief 
 * @else
 * @brief Gets a character string of the date and time.
 * @endif
 */
std::string getDatetimeString() 
{
    time_t t = time(NULL);
    struct tm *local = localtime(&t);
    std::stringstream ss;
    ss.fill('0');
    ss.width(4);
    ss << (local->tm_year + 1900) << "/";
    ss.fill('0');
    ss.width(2);
    ss << (local->tm_mon + 1) << "/";
    ss.fill('0');
    ss.width(2);
    ss << local->tm_mday;
    ss << " ";
    ss.fill('0');
    ss.width(2);
    ss << local->tm_hour;
    ss.fill('0');
    ss.width(2);
    ss << local->tm_min;
    return ss.str();

}

};
