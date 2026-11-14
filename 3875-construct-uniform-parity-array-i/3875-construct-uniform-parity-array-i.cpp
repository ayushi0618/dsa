class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_val = *min_element(nums1.begin(), nums1.end());
        bool has_odd = false, has_even = false;
        for (int x : nums1) {
            if (x % 2 == 0) has_even = true;
            else has_odd = true;
        }
        if (!has_odd || !has_even) return true;
        return has_odd;
    }
};