#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = static_cast<int>(parent.size());
        vector<vector<int>> orig_adj(n);
        for (int i = 1; i < n; ++i) {
            orig_adj[parent[i]].push_back(i);
        }

        vector<int> new_parent = parent;
        vector<int> last_seen(26, -1);

        auto assign_parents = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            if (u != 0 && last_seen[c] != -1) {
                new_parent[u] = last_seen[c];
            }

            int prev = last_seen[c];
            last_seen[c] = u;

            for (int v : orig_adj[u]) {
                self(self, v);
            }

            last_seen[c] = prev;
        };

        assign_parents(assign_parents, 0);

        vector<vector<int>> final_adj(n);
        for (int i = 1; i < n; ++i) {
            final_adj[new_parent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        auto calc_sizes = [&](auto& self, int u) -> int {
            int sz = 1;
            for (int v : final_adj[u]) {
                sz += self(self, v);
            }
            return ans[u] = sz;
        };

        calc_sizes(calc_sizes, 0);
        return ans;
    }
};