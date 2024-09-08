#define CPM_PREFIXSUM
#include "../cpmlib.hpp"
template <typename T> class PreSums{
    public:
    vector<T> pre;
    PreSums(vector<T> &v){
        int n = v.size();
        pre.resize(n+1);
        pre[0] = 0;
        for (int i = 0; i < n; i++){
            pre[i+1] = pre[i] + v[i];
        }
    }
    T sum(int start = 0, int end = -1){
        if (end < 0){
            end += pre.size();
        }
        return pre[end+1] - pre[start];
    }
};

