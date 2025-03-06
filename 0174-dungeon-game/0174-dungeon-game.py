class Solution:
    def calculateMinimumHP(self, d: List[List[int]]) -> int:
        m=len(d)
        n=len(d[0])
        dp=[[0]*n for _ in range(m)]
        #base case 
        if d[m-1][n-1]<0:
            dp[m-1][n-1]=abs(d[m-1][n-1])+1
        else:
            dp[m-1][n-1]=1
        for i in range(m-1,-1,-1):
            for j in range(n-1,-1,-1):
                if i==m-1 and j==n-1:
                    continue
                if i==m-1:
                    if d[i][j]>0:
                        if d[i][j]>=dp[i][j+1]:
                            dp[i][j]=1
                        else:
                            dp[i][j]=dp[i][j+1]-d[i][j]
                    else:
                        dp[i][j]= abs(d[i][j])+dp[i][j+1]
                if j==n-1:
                    if d[i][j]>0:
                        if d[i][j]>=dp[i+1][j]:
                            dp[i][j]=1
                        else:
                            dp[i][j]=dp[i+1][j]-d[i][j]
                    else:
                        dp[i][j]= abs(d[i][j])+dp[i+1][j]
                elif i<m-1 and j<n-1:
                    mini=min(dp[i][j+1],dp[i+1][j])
                    if d[i][j]<=0:
                        dp[i][j]=abs(d[i][j])+mini
                    else:
                        if d[i][j]<mini:
                            dp[i][j]=mini-d[i][j]
                        else:
                            dp[i][j]=1 
        return dp[0][0]

        
        