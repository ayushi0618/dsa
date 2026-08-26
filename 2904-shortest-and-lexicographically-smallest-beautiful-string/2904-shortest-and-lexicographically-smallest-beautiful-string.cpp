class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";
        int l = 0, r = 0, count = 0;
        int min_len = n + 1;

        while (r < n) {
            if (s[r] == '1') count++;

            while (count == k) {
                int len = r - l + 1;
                string temp = s.substr(l, len);

                if (len < min_len) {
                    min_len = len;
                    ans = temp;
                } else if (len == min_len) {
                    if (ans == "" || temp < ans) {
                        ans = temp;
                    }
                }

                if (s[l] == '1') count--;
                l++;
            }
            r++;
        }
        return ans;
    }
};