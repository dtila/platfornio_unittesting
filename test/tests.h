#pragma once
#ifdef __GNUC__
// Avoid tons of warnings with root code
#pragma GCC system_header

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-function-type"
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"

#include <unity.h>
#include <ArduinoFake.h>
//#include <fakeit/fakeit_root.hpp>

#pragma GCC diagnostic pop
#endif
