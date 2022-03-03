#pragma once


// used for import/export in application and engine
#ifdef EN_PLATFORM_WINDOWS
	#ifdef EN_BUILD_DLL
		#define ENIGNE_API __declspec(dllexport)
	#else
		#define ENIGNE_API __declspec(dllimport)
	#endif
#else
	#error Enigne only supports Windows - idk why..
#endif