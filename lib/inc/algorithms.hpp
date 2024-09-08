#ifndef CPM_PREFIXSUM
#define CPM_PREFIXSUM
#include "../cpmlib.hpp"
// Computes prefix sums
template <typename T> class PreSums{
    public:
    vector<T> pre;
    // Constructor
    PreSums(vector<T> &v);
    // Range Sum [start, end] (inclusive)
    T sum(int start = 0, int end = pre.size() - 1);
};

#endif