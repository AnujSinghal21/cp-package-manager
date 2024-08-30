#ifndef CPM_BITSTRING
#define CPM_BITSTRING
#include "../../lib/cpmlib.hpp"
// convert a given integer x to its binary string, can pad to fixed length
string bit_string(int x, int pad=-1);
#endif