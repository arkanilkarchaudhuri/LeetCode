class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp1, mp2;
        int n1=nums1.size();
        int n2=nums2.size();
        for(int i=0; i<n1; i++){
            mp1[nums1[i]]++;
        }
        for(int i=0; i<n2; i++){
            mp2[nums2[i]]++;
        }
        vector<int> ans1, ans2;
        for(auto it: mp1){
            if(!mp2[it.first]){
                ans1.push_back(it.first);
            }
        }
        for(auto it: mp2){
            if(!mp1[it.first]){
                ans2.push_back(it.first);
            }
        }
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};