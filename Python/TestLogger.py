#!/usr/bin/env python3
# -*- coding: utf-8 -*-


import OpenRTM_aist


class TestLogger(OpenRTM_aist.LogstreamBase):

    def __init__(self):
        OpenRTM_aist.LogstreamBase.__init__(self)
        self._header = ""

    def __del__(self):
        pass

    def init(self, prop):
        self._header = prop.getProperty("header")
        return True

    def log(self, msg, level, name):
        print(self._header+":"+msg)
        return True

    def setLogLevel(self, level):
        pass

    def shutdown(self):
        return True


def TestLoggerInit(mgr):
    OpenRTM_aist.LogstreamFactory.instance().addFactory("testlogger",
                                                        TestLogger)
