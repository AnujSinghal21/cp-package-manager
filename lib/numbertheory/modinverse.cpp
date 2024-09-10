#define CPM_MODINVERSE
#include "../cpmlib.hpp"
int modInv(int n, int p){
    return modPow(n,p-2,p);
}
