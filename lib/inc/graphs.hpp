#ifndef CPM_TREEINPUT
#include "../graphs/treeInput.cpp"
#endif

#ifndef CPM_TREE_ANCESTOR
// store the 1,2,4,... ancestor of nodes in kthPar
int log_ancestor_tree(int x, vi& seq, vvi &gr, vvi &kthPar);
// give k'th ancestor of node x (root=0) using log_ancestor_tree (kthPar)
int kth_ancestor_tree(int x, int k, vvi &kthPar);
// Returns the lowest common ancestor of nodes x and y in tree, given log_ancestor_tree and depth (from root) info
int lowest_common_ancestor(int x, int y, vvi &kthPar, vi &depth);
#endif