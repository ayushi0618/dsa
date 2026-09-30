class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.size());
        int depth = 0;
        
        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i] == '(') {
                // Alternate groups based on depth parity
                res[i] = depth % 2;
                depth++;
            } else {
                depth--;
                res[i] = depth % 2;
            }
        }
        
        return res;
    }
};