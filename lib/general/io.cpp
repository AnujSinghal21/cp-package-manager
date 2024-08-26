#define CPM_IO
#include "../../lib/cpmlib.hpp"
void print(int x, char end='\n'){
    cout << x << end;
}
void print(vector<int> &v, char sep=' ',char end='\n'){
    for(auto x: v){
        cout << x << sep;
    }
    cout << end;
}
void print(pair<int, int> p, char end='\n'){
    cout << p.first << " " << p.second << end;
}
