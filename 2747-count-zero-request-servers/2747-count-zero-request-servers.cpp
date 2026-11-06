#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        
        // Store queries with their original indices
        vector<pair<int, int>> sortedQueries(m);
        for (int i = 0; i < m; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        
        // Sort queries by time
        sort(sortedQueries.begin(), sortedQueries.end());
        // Sort logs by time
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        unordered_map<int, int> serverCount;
        int left = 0, right = 0;
        int totalLogs = logs.size();
        
        for (int i = 0; i < m; ++i) {
            int qTime = sortedQueries[i].first;
            int qIndex = sortedQueries[i].second;
            int windowStart = qTime - x;
            
            // Expand right boundary: include all logs <= qTime
            while (right < totalLogs && logs[right][1] <= qTime) {
                serverCount[logs[right][0]]++;
                right++;
            }
            
            // Shrink left boundary: remove logs < windowStart
            while (left < totalLogs && logs[left][1] < windowStart) {
                serverCount[logs[left][0]]--;
                if (serverCount[logs[left][0]] == 0) {
                    serverCount.erase(logs[left][0]);
                }
                left++;
            }
            
            // Servers with zero requests = total servers - servers with at least one request
            ans[qIndex] = n - serverCount.size();
        }
        
        return ans;
    }
};