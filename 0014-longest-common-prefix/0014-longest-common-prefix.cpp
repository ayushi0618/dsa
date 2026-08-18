#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        
        // Start by assuming the first string is the common prefix
        string prefix = strs[0];
        
        // Compare the assumed prefix with every other string in the array
        for (int i = 1; i < strs.size(); i++) {
            // While the current string doesn't start with the current prefix,
            // continuously shorten the prefix by 1 character from the end.
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                
                // If the prefix becomes empty, there is no common prefix at all
                if (prefix.empty()) {
                    return "";
                }
            }
        }
        
        return prefix;
    }
};