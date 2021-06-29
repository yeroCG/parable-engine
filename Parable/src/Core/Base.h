#pragma once

// Common includes for internal engine classes

#include <memory>

#include "Platform/PlatformDetection.h"

// build config stuff
#ifdef PBL_DEBUG
    #if defined(PBL_PLATFORM_WINDOWS)
		#define PBL_DEBUGBREAK() __debugbreak()
	#elif defined(PBL_PLATFORM_LINUX)
		#include <signal.h>
		#define PBL_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Debugbreak not supproted on platform"
	#endif
#elif PBL_RELEASE
    #define PBL_DEBUGBREAK()
#else
    #error "Undefined build configuration"
#endif

#include "Core/Log.h"
#include "Core/Assert.h"

#define BIT(x) (1 << x)

#define PBL_BIND_EVENT_HANDLER(func) std::bind(std::mem_fn(&func), this, _1)