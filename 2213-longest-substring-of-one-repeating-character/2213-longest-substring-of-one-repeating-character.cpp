#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Define what each segment tree node stores
class Node {
public:
    int len;
    int maxLen;
    int prefLen;
    int suffLen;
    char prefChar;
    char suffChar;

    Node() {
        len = maxLen = prefLen = suffLen = 0;
        prefChar = suffChar = ' ';
    }

    // Constructor for a leaf node (a single character)
    Node(char c) {
        len = maxLen = prefLen = suffLen = 1;
        prefChar = suffChar = c;
    }
};

class Solution {
    vector<Node> tree;

    // Helper function to merge two child nodes into a parent node
    Node merge(const Node& left, const Node& right) {
        if (left.len == 0) return right;
        if (right.len == 0) return left;

        Node res;
        res.len = left.len + right.len;
        res.prefChar = left.prefChar;
        res.suffChar = right.suffChar;

        // 1. Calculate new prefix length
        res.prefLen = left.prefLen;
        if (left.prefLen == left.len && left.prefChar == right.prefChar) {
            res.prefLen += right.prefLen;
        }

        // 2. Calculate new suffix length
        res.suffLen = right.suffLen;
        if (right.suffLen == right.len && right.suffChar == left.suffChar) {
            res.suffLen += left.suffLen;
        }

        // 3. Calculate max length (could be entirely in left, entirely in right, or crossing the boundary)
        res.maxLen = max({left.maxLen, right.maxLen, res.prefLen, res.suffLen});
        if (left.suffChar == right.prefChar) {
            res.maxLen = max(res.maxLen, left.suffLen + right.prefLen);
        }

        return res;
    }

    // Build the initial segment tree
    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = Node(s[start]);
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    // Point update to change a character and recalculate
    void update(int node, int start, int end, int idx, char c) {
        if (start == end) {
            tree[node] = Node(c);
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, c);
        } else {
            update(2 * node + 1, mid + 1, end, idx, c);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        // Allocate space for the segment tree (4 * N is safe)
        tree.resize(4 * n + 1);
        
        // Build the tree for the initial string
        build(1, 0, n - 1, s);

        int k = queryCharacters.length();
        vector<int> ans(k);

        // Process each query
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            // The root node (index 1) always holds the max length for the entire string
            ans[i] = tree[1].maxLen; 
        }

        return ans;
    }
};