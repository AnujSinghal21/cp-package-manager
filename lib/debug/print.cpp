#define CPM_DEBUGPRINT
#include "../cpmlib.hpp"
string dbg_string(int x){
    return to_string(x);
}
string dbg_string(string s){
    return s;
}
template <typename T1, typename T2> string dbg_string(pair<T1, T2> &p){
    string s = "{ ";
    s += dbg_string(p.first);
    s += " , ";
    s += dbg_string(p.second);
    s += " }";
    return s;
}
template <typename T> string dbg_string(vector<T> & v){
    string s = "[ ";
    for (auto &e: v){
        s += dbg_string(e);
        s += " ";
    }
    s += "]";
    return s;
}
#define debug(x) cerr << "L" << __LINE__ << ": " << #x << " = " << dbg_string(x) << endl;