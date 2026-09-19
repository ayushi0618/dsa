class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        int sLen = s.length();

        if (sLen < totalLen) return result;

        unordered_map<string, int> wordMap;
        for (const string& word : words) {
            wordMap[word]++;
        }

        // Iterate through all possible wordLen starting offsets
        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i;
            unordered_map<string, int> windowMap;
            int count = 0;

            while (right + wordLen <= sLen) {
                // Extract the next word from the right
                string sub = s.substr(right, wordLen);
                right += wordLen;

                // Check if the word is valid
                if (wordMap.find(sub) != wordMap.end()) {
                    windowMap[sub]++;
                    count++;

                    // If the word count exceeds the expected count, shrink from the left
                    while (windowMap[sub] > wordMap[sub]) {
                        string leftSub = s.substr(left, wordLen);
                        windowMap[leftSub]--;
                        left += wordLen;
                        count--;
                    }

                    // If all words matched, record the starting index
                    if (count == numWords) {
                        result.push_back(left);
                        // Shift window by one word to search for the next match
                        string leftSub = s.substr(left, wordLen);
                        windowMap[leftSub]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    // Reset the window if an invalid word is encountered
                    windowMap.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};