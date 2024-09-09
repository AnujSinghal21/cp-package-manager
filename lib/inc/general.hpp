#ifndef CPM_CONSTANTS
#define CPM_CONSTANTS
const int mod = 1e9 + 7;
const int mx5 = 2e5 + 5;
const int mx6 = 1e6 + 6;
const int mx7 = 1e7 + 7;
const int inf = 1e18;
const double eps = 1e-5;
#endif

#ifndef CPM_IO
#define CPM_IO
#include "../cpmlib.hpp"
#define get_vec(name, size, type) vector<type> name(size); for (int i = 0; i < size; i++){cin >> name[i];}  
void print(int x, char end='\n');
void print(vector<int> &v, char sep=' ',char end='\n');
void print(pair<int, int> p, char end='\n');
template<typename T> void input(vector<T> &v);
template<typename T> T input(T &v);
#endif

#ifndef CPM_MACROS
#include "../general/macros.cpp"
#endif

