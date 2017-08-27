#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <string>
#include <ctime>

namespace Util {
// Get current date/time format YYYY-MM-DD.HH-MM-SS
const std::string CurrentDateTime()
{
  time_t now = time(NULL);
  struct tm *tstruct;
  char       buf[80];

  tstruct = localtime(&now);
  strftime(buf, sizeof(buf), "%Y-%m-%d.%X", tstruct);
  return buf;
}
}

#endif // UTILITIES_H
