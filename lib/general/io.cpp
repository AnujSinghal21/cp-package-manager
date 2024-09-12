// #define CPM_IO
#include "./../cpmlib.hpp"

#define get_vec(name, size, type) vector<type> name(size); for (int i = 0; i < size; i++){cin >> name[i];}  
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

template<typename T> void input(vector<T> &v){
    for (int i = 0; i < v.size(); i++){
        cin >> v[i];
    }
}

template<typename T> T input(T &v){
    cin >> v;
}
int impos(string msg="-1", string end="\n"){
    cout << msg << end;
    return -1;
}