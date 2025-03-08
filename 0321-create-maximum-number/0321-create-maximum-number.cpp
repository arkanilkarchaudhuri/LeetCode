#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result;
        int m = nums1.size(), n = nums2.size();
        
        for (int i = max(0, k - n); i <= min(k, m); ++i) {
            vector<int> subsequence1 = getMaxSubsequence(nums1, i);
            vector<int> subsequence2 = getMaxSubsequence(nums2, k - i);
            vector<int> candidate = merge(subsequence1, subsequence2);
            if (result.empty() || candidate > result) {
                result = candidate;
            }
        }
        
        return result;
    }

private:
    vector<int> getMaxSubsequence(vector<int>& nums, int k) {
        vector<int> stack;
        int drop = nums.size() - k;
        for (int num : nums) {
            while (!stack.empty() && stack.back() < num && drop > 0) {
                stack.pop_back();
                --drop;
            }
            if (stack.size() < k) {
                stack.push_back(num);
            } else {
                --drop;
            }
        }
        return stack;
    }
    
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        auto it1 = nums1.begin(), it2 = nums2.begin();
        while (it1 != nums1.end() || it2 != nums2.end()) {
            if (lexicographical_compare(it1, nums1.end(), it2, nums2.end())) {
                merged.push_back(*it2++);
            } else {
                merged.push_back(*it1++);
            }
        }
        return merged;
    }
};
