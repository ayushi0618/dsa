#include <vector>
#include <queue>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<int> busiestServers(int k, std::vector<int>& arrival, std::vector<int>& load) {
        // Min-heap to store busy servers: pairs of {free_time, server_id}
        std::priority_queue<std::pair<long long, int>, 
                            std::vector<std::pair<long long, int>>, 
                            std::greater<std::pair<long long, int>>> busyServers;
        
        // Set to store currently available server IDs
        std::set<int> availableServers;
        for (int i = 0; i < k; ++i) {
            availableServers.insert(i);
        }
        
        std::vector<int> requestCount(k, 0);
        int maxRequests = 0;
        
        for (int i = 0; i < arrival.size(); ++i) {
            long long currTime = arrival[i];
            
            // Free up servers whose tasks have finished by currTime
            while (!busyServers.empty() && busyServers.top().first <= currTime) {
                availableServers.insert(busyServers.top().second);
                busyServers.pop();
            }
            
            // If all servers are busy, drop the request
            if (availableServers.empty()) {
                continue;
            }
            
            // Find the preferred server using lower_bound starting from (i % k)
            int target = i % k;
            auto it = availableServers.lower_bound(target);
            
            // If no server >= target is available, wrap around to the beginning
            if (it == availableServers.end()) {
                it = availableServers.begin();
            }
            
            int assignedServer = *it;
            availableServers.erase(it);
            
            // Assign the task to the server
            busyServers.push({currTime + load[i], assignedServer});
            requestCount[assignedServer]++;
            maxRequests = std::max(maxRequests, requestCount[assignedServer]);
        }
        
        // Collect all servers that handled the maximum number of requests
        std::vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (requestCount[i] == maxRequests) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};