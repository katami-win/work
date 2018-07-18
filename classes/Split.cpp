// -*- C++ -*-
/*!
 * @file Split.cpp
 * @brief
 * @date $Date: 2014-06-17 10:10:29 +0900 (Tue, 17 Jun 2014) $
 *
 
 * $Id: Split.cpp 180 2014-06-17 01:10:29Z pi $
 *
 */

#include "Split.h"


namespace WEIApp
{

/*!
 * @if jp
 * @brief 
 * @else
 * @brief Erase the head blank characters of string
 * @endif
 */
void eraseHeadBlank(std::string& str)
{
  if (str.empty()) return;
  while (str[0] == ' ' || str[0] == '\t') str.erase(0, 1);


}
/*!
 * @if jp
 * @brief
 * @else
 * @brief Check whether the character is escaped or not
 * @endif
 */
bool isEscaped(const std::string& str, std::string::size_type pos)
{
  --pos;
  unsigned int i;
  for (i = 0; (pos >= 0) && str[pos] == '\\'; --pos, ++i) ;
  // If the number of \ is odd, delimiter is escaped.
  return (i % 2) == 1;
}
/*!
 * @if jp
 * @brief
 * @else
 * @brief Erase the tail blank characters of string
 * @endif
 */
void eraseTailBlank(std::string& str)
{
  if (str.empty()) return;
  while ((str[str.size() - 1] == ' ' || str[str.size() - 1] == '\t') &&
         !isEscaped(str, str.size() - 1))
    str.erase(str.size() - 1, 1);
}

/*!
 * @if jp
 * @brief
 * @else
 * @brief Split string by delimiter
 * @endif
  */
std::vector<std::string> split(const std::string& input,
                const std::string& delimiter,
                bool ignore_empty)
{
    typedef std::string::size_type size;
    std::vector<std::string> results;
    size delim_size = delimiter.size();
    size found_pos(0), begin_pos(0), pre_pos(0), substr_size(0);
    
    if (input.empty()) return results;
    
    
    while (1)
      {
        //    REFIND:
        found_pos = input.find(delimiter, begin_pos);
        if (found_pos == std::string::npos) 
          {
            std::string substr(input.substr(pre_pos));
            eraseHeadBlank(substr);
            eraseTailBlank(substr);
            if (!(substr.empty() && ignore_empty)) results.push_back(substr);
            break;
          }
        substr_size = found_pos - pre_pos;
        if (substr_size >= 0)
          {
            std::string substr(input.substr(pre_pos, substr_size));
            eraseHeadBlank(substr);
            eraseTailBlank(substr);
            if (!(substr.empty() && ignore_empty)) results.push_back(substr);
          }
        begin_pos = found_pos + delim_size;
        pre_pos   = found_pos + delim_size;
      }
    return results;
  }

}; //namespace col

