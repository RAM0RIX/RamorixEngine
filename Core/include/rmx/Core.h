#pragma once

#include <functional>
#include <iostream>
#include <sstream>
#include <string>

#ifdef RMX_PLATFORM_WINDOWS
#include <Windows.h>
#ifdef RMX_BUILD_DLL
#define RMX_API __declspec(dllexport)
#else
#define RMX_API __declspec(dllimport)
#endif
#elif defined(RMX_PLATFORM_LINUX)
#else
#error Hazel only supports Windows and Linux !
#endif

#define BIT(pos) (1 << pos)