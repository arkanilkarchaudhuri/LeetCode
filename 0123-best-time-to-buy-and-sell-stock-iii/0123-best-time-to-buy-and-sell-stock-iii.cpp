class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        // dp array where dp[i][k] is the max profit up to day i with at most k transactions
        vector<vector<int>> dp(n, vector<int>(3, 0));
        
        for (int k = 1; k <= 2; ++k) {
            int max_diff = -prices[0]; // Initial max_diff for the first transaction
            for (int i = 1; i < n; ++i) {
                dp[i][k] = max(dp[i-1][k], prices[i] + max_diff);
                max_diff = max(max_diff, dp[i-1][k-1] - prices[i]);
            }
        }
        
        return dp[n-1][2];
    }
};