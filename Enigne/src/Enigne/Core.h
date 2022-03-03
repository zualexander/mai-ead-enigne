
#if defined _WIN32 || defined __CYGWIN__
#ifdef EN_BUILD_DLL
#ifdef __GNUC__
#define ENIGNE_API __attribute__((dllexport))
#else
#define ENIGNE_API __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
#endif
#else
#ifdef __GNUC__
#define ENIGNE_API __attribute__((dllimport))
#else
#define ENIGNE_API __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
#endif
#endif
#else
#if __GNUC__ >= 4
#define ENIGNE_API __attribute__((visibility("default")))
#else
#define ENIGNE_API
#endif
#endif