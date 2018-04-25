// -*- C++ -*-
/*!
 * @file Split.h
 * @brief 
 * @date $Date: 2014-06-17 10:10:29 +0900 (Tue, 17 Jun 2014) $
 *
 * $Id: Split.h 180 2014-06-17 01:10:29Z pi $
 *
 */

#ifndef WEI_SPLIT_H
#define WEI_SPLIT_H

#include <vector>
#include <string>

namespace WEIApp 
{

  std::vector<std::string> split(const std::string& input,
                const std::string& delimiter,
                bool ignore_empty);
};

#endif // WEI_SPLIT_H

