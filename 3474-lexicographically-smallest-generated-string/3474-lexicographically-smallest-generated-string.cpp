class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int len = n + m - 1;
        string word(len, '?');

        // Step 1: Assign fixed parts where str1[i] == 'T'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != '?' && word[i + j] != str2[j]) {
                        return "";
                    }
                    word[i + j] = str2[j];
                }
            }
        }

        // Step 2: Fill remaining wildcards with 'a' for lexicographically smallest result
        for (int i = 0; i < len; i++) {
            if (word[i] == '?') {
                word[i] = 'a';
            }
        }

        // Step 3: Handle 'F' constraints by modifying characters from right to left if a match occurs
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool fixed = false;
                    // Try to break the equality by changing the rightmost available character in the window
                    for (int j = m - 1; j >= 0; j--) {
                        int idx = i + j;
                        // Check if this position was originally a wildcard (i.e. not locked by an overlapping 'T')
                        // To be safe against locks, we can check if changing it violates any 'T' constraint,
                        // or we can iterate through characters ('b', 'c', etc.) until it no longer matches.
                        // Here, we check character increments up to 'z'.
                        char original = word[idx];
                        for (char c = original + 1; c <= 'z'; c++) {
                            word[idx] = c;
                            // Verify if this change breaks the 'F' match while keeping all 'T' constraints valid
                            bool valid = true;
                            // Quick check: ensure no 'T' constraint is broken
                            // A complete check re-evaluates 'T' constraints overlapping with idx
                            bool t_conflict = false;
                            for (int k = max(0, idx - m + 1); k <= min(n - 1, idx); k++) {
                                if (str1[k] == 'T') {
                                    bool sub_match = true;
                                    for (int l = 0; l < m; l++) {
                                        if (word[k + l] != str2[l]) {
                                            sub_match = false;
                                            break;
                                        }
                                    }
                                    if (!sub_match) {
                                        t_conflict = true;
                                        break;
                                    }
                                }
                            }

                            if (!t_conflict) {
                                fixed = true;
                                break;
                            }
                        }
                        if (fixed) break;
                        word[idx] = original; // backtrack if unsuccessful
                    }
                    if (!fixed) return "";
                }
            }
        }

        // Final verification pass across all constraints
        for (int i = 0; i < n; i++) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (word[i + j] != str2[j]) {
                    match = false;
                    break;
                }
            }
            if ((str1[i] == 'T' && !match) || (str1[i] == 'F' && match)) {
                return "";
            }
        }

        return word;
    }
};