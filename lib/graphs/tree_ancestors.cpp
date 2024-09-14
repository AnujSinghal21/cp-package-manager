#define CPM_TREE_ANCESTOR
#include "../cpmlib.hpp"

vi logseq(vi & seq){
    vi s;
    for (int i = 1; i <= seq.size(); i *= 2){
        s.push_back(seq[seq.size() - i]);
    }
    return s;
}
int log_ancestor_tree(int x, vi& seq, vvi &gr, vvi &kthPar){
    kthPar[x] = logseq(seq);
    seq.push_back(x);
    repe(y, gr[x]){
        log_ancestor_tree(y, seq, gr, kthPar);
    }
    seq.pop_back();
    return 0;
}
int kth_ancestor_tree(int x, int k, vvi &kthPar){
    int l = 0;
    while(k){
        if (k & 1){
            if (l >= kthPar[x].size()){
                x = -1;
                break;
            }
            x = kthPar[x][l];
        }
        l++;
        k >>= 1;
    }
    return x;
}
int lowest_common_ancestor(int x, int y, vvi &kthPar, vi &depth){
    if(depth[x] < depth[y]){
        swap(x, y);
    }
    x = kth_ancestor_tree(x, depth[x] - depth[y], kthPar);
    int j = 0;
    while (x != y){
        while (j < kthPar[x].size()){
            if (kthPar[x][j] == kthPar[y][j]) break;
            j++;
        }
        if (j == 0){
            j = 1;
        }
        x = kthPar[x][j-1];
        y = kthPar[y][j-1];
        j = 0;
    }
    return x;
}