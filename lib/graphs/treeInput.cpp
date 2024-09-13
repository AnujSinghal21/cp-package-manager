#define CPM_TREEINPUT
#include "../cpmlib.hpp"
#define input_bdtree(name, size) vector<vector<int> > name(size); \
for(int i = 1; i < n; i++){ \
    int temp_x, temp_y; \
    cin >> temp_x >> temp_y;\
    name[temp_x - 1].push_back(temp_y-1);\
    name[temp_y - 1].push_back(temp_x-1);\
}