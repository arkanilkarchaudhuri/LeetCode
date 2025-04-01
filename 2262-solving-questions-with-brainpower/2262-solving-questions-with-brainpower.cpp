class Solution {
public:
    long long solve(int idx,int n,vector<vector<int>>& questions,vector<long long>&dp){
        if(idx>=n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        long long take=questions[idx][0]+solve(idx+questions[idx][1]+1,n,questions,dp);
        long long ntake=solve(idx+1,n,questions,dp);
        return dp[idx]=max(take,ntake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int idx=0;
        int n=questions.size();
        vector<long long>dp(n+1,-1);
        return solve(idx,n,questions,dp);
    }
};