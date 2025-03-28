class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& q) { 
        int n = grid.size(), m = grid[0].size(), x = q.size(), count = 0;
        if (n == 0 || m == 0) return vector<int>(x, 0); 
        vector<vector<int>> v(x);  
        for (int i = 0; i < x; i++) {
            v[i] = {q[i], i};
        } 
        sort(v.begin(), v.end()); 
        vector<int> ans(x); 
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq; 
        pq.push({grid[0][0], 0, 0});  
        vis[0][0] = 1; 
        for (auto it : v) {
            int val = it[0], idx = it[1];
            while (!pq.empty()) {
                auto [value, i, j] = pq.top();
                if (value >= val) break;
                pq.pop();
                count++; 
                if (i - 1 >= 0 && !vis[i - 1][j]) {
                    pq.push({grid[i - 1][j], i - 1, j});
                    vis[i - 1][j] = 1;
                }
                if (i + 1 < n && !vis[i + 1][j]) {
                    pq.push({grid[i + 1][j], i + 1, j});
                    vis[i + 1][j] = 1;
                }
                if (j - 1 >= 0 && !vis[i][j - 1]) {
                    pq.push({grid[i][j - 1], i, j - 1});
                    vis[i][j - 1] = 1;
                }
                if (j + 1 < m && !vis[i][j + 1]) {
                    pq.push({grid[i][j + 1], i, j + 1});
                    vis[i][j + 1] = 1;
                }
            }
            ans[idx] = count;
        } 
        return ans;
    }
};