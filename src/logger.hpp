#pragma once
#include "mstring.hpp"

class Logger {
  public:
  /*
   * Default ctor
   */
  Logger();

  /*
   * Copy ctor
   */
  Logger(const Logger& rLogger);

  /*
   * Move ctor
   */
  Logger(Logger&& rLogger) noexcept;
  /*
   * Dtor
   */
  ~Logger() noexcept;
  /*
   * Copy assign op
   */
  Logger& operator=(const Logger& rLogger);

  /*
   * Move assign op
   */
  Logger& operator=(Logger&& rLogger);

  void memoryAllocation();

  private:
  mstring mLastMsg;
};
