#include "clogger.h"
#include "utilities.h"

const string CLogger::m_sFileName = "Log.txt";
CLogger     *CLogger::m_pThis     = NULL;
ofstream     CLogger::m_Logfile;
CLogger::CLogger()
{}

CLogger * CLogger::GetLogger() {
  if (m_pThis == NULL) {
    m_pThis = new CLogger();
    m_Logfile.open(m_sFileName.c_str(), ios::out | ios::app);
  }
  return m_pThis;
}

void CLogger::Log(const char *pFormat, ...)
{
  char   *pMessage = nullptr;
  int     nLength  = 0;
  va_list args;

  va_start(args, pFormat);
  nLength  = vsnprintf(NULL, 0, pFormat, args) + 1;
  pMessage = new char[nLength];
  vsprintf(pMessage, pFormat, args);
  m_Logfile << Util::CurrentDateTime() << '\t';
  m_Logfile << pMessage << '\n';
  va_end(args);

  delete[] pMessage;
}

void CLogger::Log(const string& sMessage)
{
  m_Logfile <<  Util::CurrentDateTime() << ":\t";
  m_Logfile << sMessage << "\n";
}

CLogger& CLogger::operator<<(const string& sMessage)
{
  m_Logfile << "\n" << Util::CurrentDateTime() << ":\t";
  m_Logfile << sMessage << "\n";
  return *this;
}
