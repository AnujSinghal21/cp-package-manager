#define CPM_BITSTRING
#include "../../lib/cpmlib.hpp"
string bit_string(int x, int pad=-1){
    string s;
    while (x){
        s.push_back((x & 1) + '0');
        x >>= 1;
    }
    while (s.size() < pad){
        s.push_back('0');
    }
    reverse(s.begin(), s.end());
    return s;
}
