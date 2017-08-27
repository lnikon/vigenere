#ifndef CLOGGER_H
#define CLOGGER_H

#include <fstream>
#include <iostream>
#include <string>
#include <cstdarg>

using namespace std;

#define LOGGER CLogger::GetLogger()

class CLogger {
public:

  void            Log(const std::string& sMessage);
  void            Log(const char *pParam,
                      ...);
  CLogger       & operator<<(const string& sMessage);
  static CLogger* GetLogger();

private:

  CLogger();
  CLogger(const CLogger&);
  ~CLogger();

  CLogger& operator=(const CLogger&)
  {
    return *this;
  }

  // In C++11 we can use class member init-rs
  static const std::string m_sFileName;
  static CLogger *m_pThis;
  static ofstream m_Logfile;
};

#endif // CLOGGER_H
