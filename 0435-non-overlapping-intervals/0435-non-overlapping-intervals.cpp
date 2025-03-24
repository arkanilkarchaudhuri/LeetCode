class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            v.push_back(i);
        }
        sort(v.begin(),v.end(),[&](int a, int b){
            return intervals[a][1]<intervals[b][1];
        });
        int count =0;
        int endValue = intervals[v[0]][1];
        for(int i=1;i<n;i++){
            if(intervals[v[i]][0]>=endValue){
                endValue = intervals[v[i]][1];
            }
            else{
                count++;
                cout<<v[i];
            }
        }
        return count;
    }
};