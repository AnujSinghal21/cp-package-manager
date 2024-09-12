#define CPM_MODFIELD
#include "../cpmlib.hpp"
template <int m = 1000000007> class Field {
    public:
    int v;
    Field(int x) {
        v = (x < 0)? x%m + m: x;
    }
    Field operator+(const Field a){
        return Field<m>((v + a.v) % m);
    }
    Field operator-(const Field a){
        int x = v - a.v;
        if (x < 0){
            return Field<m>(x + m);
        }
        return Field<m>(x % m);
    }
    Field operator*(const Field a){
        long long x = (long long)v * a.v;
        return Field<m>(x % m);
    }
    Field operator/(Field a){
        return Field<m>(((long long)v * (~a).v) % m);
    }
    Field operator~(){
        return Field<m>(Field<m>(v) ^ (m - 2));
    }
    Field operator^(int b){
        if (b < 0){
            return (~(*this)) ^ (-b); 
        }
        int a = v;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return Field<m>(res);        
    }
};