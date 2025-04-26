class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int first=-1,second=-1,third=-1;
        long result = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<minK || nums[i]>maxK) first = i;
            if(nums[i] == minK) second = i;
            if(nums[i] == maxK) third = i;
            result += max(0, min(second, third)-first);
        }
        return result;
    }
};