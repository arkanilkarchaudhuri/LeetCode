class Solution {
public:
    int countDays(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());  
        int ans = 0, prev = 0; 
        for(auto &m : meetings) {
            int start = m[0], end = m[1]; 
            if(start > prev+1)ans+=(start-prev-1); 
            prev = max(prev, end);
        } 
        if(prev < n) ans += (n-prev); 
        return ans;
    }
};