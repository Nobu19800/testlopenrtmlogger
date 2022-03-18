#include "TestLogger.h"
#include <iostream>


TestLoggerStream::TestLoggerStream()
{
}

TestLoggerStream::~TestLoggerStream()
{
}

bool TestLoggerStream::init(const coil::Properties& prop)
{
  header = prop["header"];
  return true;
}

void TestLoggerStream::write(int level, const std::string& name, const std::string& date, const std::string& mes)
{
  std::cout << header << ":" << mes << std::endl;
}


TestLogger::TestLogger()
{
}

TestLogger::~TestLogger()
{
}

bool TestLogger::init(const coil::Properties& prop)
{
  m_logstream.init(prop);
  return true;
}

coil::LogStreamBuffer* TestLogger::getStreamBuffer()
{
  return &m_logstream;
}


extern "C"
{
  void TestLoggerInit()
  {
    ::RTC::LogstreamFactory::
      instance().addFactory("testlogger",
                            ::coil::Creator< ::RTC::LogstreamBase,
                                             TestLogger>,
                            ::coil::Destructor< ::RTC::LogstreamBase,
                                                TestLogger>);
  }
}
