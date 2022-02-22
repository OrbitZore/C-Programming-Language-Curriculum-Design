#include "cardinal.hpp"

#ifdef _WIN32
inline const string config_dir=string(getenv("appdata"))+"\\";
#else
inline const string config_dir=string(getenv("HOME"))+"/.config/";
#endif
