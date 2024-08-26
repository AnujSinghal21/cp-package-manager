#ifndef CPM_IO
#define CPM_IO
#include "../../lib/cpmlib.hpp"
void print(int x, char end='\n');
void print(vector<int> &v, char sep=' ',char end='\n');
void print(pair<int, int> p, char end='\n');
#endif