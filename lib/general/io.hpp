#ifndef CPM_IO
#define CPM_IO
#include "../../lib/cpmlib.hpp"
#define get_vec(name, size, type) vector<type> name(size); for (int i = 0; i < size; i++){cin >> name[i];}  
void print(int x, char end='\n');
void print(vector<int> &v, char sep=' ',char end='\n');
void print(pair<int, int> p, char end='\n');
template<typename T> void input(vector<T> &v);
template<typename T> T input(T &v);
#endif