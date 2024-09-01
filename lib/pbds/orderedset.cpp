#define CPM_ORDERED_SET
#include "../../lib/cpmlib.hpp"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using OrderedSet = tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>;
