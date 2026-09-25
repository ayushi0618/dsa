#include <vector>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> braceExpansionII(std::string expression) {
        std::set<std::string> result = parse(expression);
        return std::vector<std::string>(result.begin(), result.end());
    }

private:
    std::set<std::string> parse(const std::string& expr) {
        std::vector<std::set<std::string>> groups;
        groups.push_back({""}); // Start with an empty string for concatenation
        
        int i = 0;
        while (i < expr.length()) {
            if (expr[i] == '{') {
                int braceCount = 0;
                int start = i;
                while (i < expr.length()) {
                    if (expr[i] == '{') braceCount++;
                    else if (expr[i] == '}') braceCount--;
                    i++;
                    if (braceCount == 0) break;
                }
                // Extract inner expression inside the braces
                std::set<std::string> inner = parse(expr.substr(start + 1, i - start - 2));
                std::vector<std::set<std::string>> nextGroups;
                for (const auto& g : groups) {
                    for (const auto& w : inner) {
                        std::set<std::string> temp;
                        for (const auto& gw : g) {
                            nextGroups.push_back({gw + w});
                        }
                    }
                }
                // If there are multiple groups from concatenation, we combine them appropriately
                // Alternatively, standard cartesian product with existing groups:
                groups = cartesianProduct(groups, inner);
            } else if (expr[i] == ',') {
                groups.push_back({""});
                i++;
            } else {
                // Regular character
                std::string s = "";
                while (i < expr.length() && std::isalpha(expr[i])) {
                    s += expr[i];
                    i++;
                }
                std::set<std::string> inner = {s};
                groups = cartesianProduct(groups, inner);
            }
        }
        
        std::set<std::string> resultSet;
        for (const auto& g : groups) {
            resultSet.insert(g.begin(), g.end());
        }
        return resultSet;
    }

    std::vector<std::set<std::string>> cartesianProduct(const std::vector<std::set<std::string>>& groups, const std::set<std::string>& inner) {
        std::vector<std::set<std::string>> result;
        // The last group handles the current concatenation chain
        for (size_t j = 0; j < groups.size() - 1; ++j) {
            result.push_back(groups[j]);
        }
        
        const auto& lastGroup = groups.back();
        std::set<std::string> newGroup;
        for (const auto& w1 : lastGroup) {
            for (const auto& w2 : inner) {
                newGroup.insert(w1 + w2);
            }
        }
        result.push_back(newGroup);
        return result;
    }
};