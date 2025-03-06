class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        for(int i = 0; i<n; i++){
            unordered_map<double,int> map;
            for(int j = i+1; j<n; j++){
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                double slope;
                if(points[j][0] == points[i][0]) slope = DBL_MAX;
                else slope = (double) (y2-y1) / (x2 - x1);
                map[slope] += 1; 
                ans = max(ans,map[slope]+1);
            }
        }
        return ans;
    }
};