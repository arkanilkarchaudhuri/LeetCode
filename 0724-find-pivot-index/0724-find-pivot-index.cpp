class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tot = 0, pre = 0;
        for (int x : nums) {
            tot += x;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (pre == tot - pre - nums[i]) {
                return i;
            }
            pre += nums[i];
        }
        return -1;
    }
};