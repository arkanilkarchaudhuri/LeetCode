class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans=0,count=0;
        unordered_map<int,long long>mp;
        mp[0]=1;
        for(int &i:nums){
            if(i%modulo==k) count++;

            int rem=(count-k+modulo)%modulo;
            ans+=mp[rem];
            
            mp[count%modulo]++;
        }
        return ans;
    }
};