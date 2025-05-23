class Solution {
public:
    bool divideArray(vector<int>& nums) {
        bool freq[501] = {};
        for (int num : nums)
            freq[num] = !freq[num];
        for (int num : nums)
            if (freq[num])
                return false;
        return true;
    }
};