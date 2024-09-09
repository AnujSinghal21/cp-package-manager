#ifndef CPM_DEBUGPRINT
#define CPM_DEBUGPRINT
#include "../cpmlib.hpp"
string dbg_string(int x);
string dbg_string(string s);
template <typename T1, typename T2> string dbg_string(pair<T1, T2> &p);
template <typename T> string dbg_string(vector<T> & v);
#define debug(x) cerr << "L" << __LINE__ << ": " << #x << " = " << dbg_string(x) << endl;

#endif