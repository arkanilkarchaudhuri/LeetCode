class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        m, n = len(s), len(p)
        
        # Create a 2D DP array with (m+1) x (n+1)
        dp = [[False] * (n + 1) for _ in range(m + 1)]
        
        # An empty string matches an empty pattern
        dp[0][0] = True
        
        # Initialize first row of dp table for patterns like "a*"
        for j in range(1, n + 1):
            if p[j - 1] == '*':
                dp[0][j] = dp[0][j - 2]
        
        # Fill the DP table
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if p[j - 1] == '*':
                    # Zero occurrence of the character before '*'
                    dp[i][j] = dp[i][j - 2]
                    # One or more occurrences of the character before '*'
                    if p[j - 2] == s[i - 1] or p[j - 2] == '.':
                        dp[i][j] = dp[i][j] or dp[i - 1][j]
                else:
                    # Single character match or '.' match
                    if p[j - 1] == s[i - 1] or p[j - 1] == '.':
                        dp[i][j] = dp[i - 1][j - 1]
        
        return dp[m][n]