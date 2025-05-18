class Solution {
public:
int mod=1e9+7;
vector<string>colState;
vector<vector<int>>dp;
void gen(string cur,char prev,int l,int m)
{
    if(l==m) 
    {
        colState.push_back(cur);
        return;
    }
    for(char ch:{'R','G','B'})
    {
        if(ch==prev) continue;
        gen(cur+ch,ch,l+1,m);
    }

}
int f(int remcol,int previdx,int rows)
{
   if(remcol==0)
   {
    return 1;
   }
   if(dp[remcol][previdx]!=-1) return dp[remcol][previdx];
   int ways=0;
   string prev=colState[previdx];
   for(int i=0;i<colState.size();i++)
   {
    if(i==previdx) continue;
    string cur=colState[i];
    bool valid=true;
    for(int j=0;j<rows;j++)
    {
       if(prev[j]==cur[j])
       {
        valid=false;
        break;
       }
    }
    if(valid) ways=(ways+f(remcol-1,i,rows))%mod;
   }
   return dp[remcol][previdx]=ways;
}
    int colorTheGrid(int m, int n) {
        gen("",'#',0,m);
        int size=colState.size();
        dp=vector<vector<int>>(n+1,vector<int>(size+1,-1));

        int ans=0;
        for(int i=0;i<colState.size();i++)
        {
            ans=(ans+f(n-1,i,m))%mod;
        }
        return ans;

    }
};