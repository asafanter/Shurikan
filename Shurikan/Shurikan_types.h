#ifndef SHURIKAN_TYPES_H
#define SHURIKAN_TYPES_H

#include <iostream>
#include <string>

#define info(msg) std::cout << msg << std::endl;

namespace Shurikan {

using int8 = char;
using int16 = short;
using int32 = int;
using int64 = long;
using int128 = long long;
using uint8 = unsigned char;
using uint16 = unsigned short;
using uint32 = unsigned int;
using uint64 = unsigned long;
using uint128 = unsigned long long;
using real32 = float;
using real64 = double;

using string = std::string;

} //namespace Shurikan



#endif // SHURIKAN_TYPES_H
