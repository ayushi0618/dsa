#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Adjacency list: u -> list of {v, weight}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // Min-priority queue storing tuples of (distance, node, consecutive_count)
        priority_queue<tuple<long long, int, int>, 
                       vector<tuple<long long, int, int>>, 
                       greater<tuple<long long, int, int>>> pq;

        // Distance table: min_dist[u][count] stores the shortest weight to reach node u with `count` consecutive identical labels
        // Since k <= 50, we can use a 2D vector or hash map. Here a vector of size n x (k + 1) works well.
        vector<vector<long long>> min_dist(n, vector<long long>(k + 1, -1));

        // Start at node 0
        int start_count = 1;
        pq.push({0, 0, start_count});
        min_dist[0][start_count] = 0;

        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();

            if (u == n - 1) {
                return d;
            }

            if (d > min_dist[u][count]) {
                continue;
            }

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int w = neighbor.second;

                int next_count = (labels[v] == labels[u]) ? count + 1 : 1;

                if (next_count > k) {
                    continue;
                }

                long long new_dist = d + w;
                if (min_dist[v][next_count] == -1 || new_dist < min_dist[v][next_count]) {
                    min_dist[v][next_count] = new_dist;
                    pq.push({new_dist, v, next_count});
                }
            }
        }

        return -1;
    }
};