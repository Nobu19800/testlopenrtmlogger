#ifndef TESTLOGGER_H
#define TESTLOGGER_H


#include <rtm/LogstreamBase.h>


class TestLoggerStream
  : public coil::LogStreamBuffer
{
public:
  TestLoggerStream();
  ~TestLoggerStream() override;
  bool init(const coil::Properties& prop);
  void write(int level, const std::string& name, const std::string& date, const std::string& mes) override;
private:
  std::string header;
};

class TestLogger
  : public RTC::LogstreamBase
{
public:
  TestLogger();
  ~TestLogger() override;
  bool init(const coil::Properties& prop) override;
  coil::LogStreamBuffer* getStreamBuffer() override;
private:
  TestLoggerStream m_logstream;
};

extern "C"
{
  void DLL_EXPORT TestLoggerInit();
}

#endif