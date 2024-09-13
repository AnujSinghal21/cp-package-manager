#define CPM_DFS
#include "../cpmlib.hpp"
int dfs(int x, int p, vvi &gr, vi &ans){
    int a = 0;
    repe(y, gr[x]){
        if (y == p) continue;
        a += dfs(y, x, gr, ans);
    }
    return ans[x] = a;
}
