TEMPLATE = app

CONFIG += qt qtestlib

TARGET = run-tests
INCLUDEPATH += ..
VPATH += ..
OBJECTS_DIR = build
MOC_DIR = build

LIBS += -llua

QMAKE_CXXFLAGS += -std=c++0x

HEADERS += \
	loaders.hpp

SOURCES += \
	Tests.cpp \
	LuaStack.cpp \
	Lua.cpp \
	types.cpp \
	loaders.cpp
