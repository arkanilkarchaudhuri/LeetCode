class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        double d1=0;int n= dim.size();
        double maxi = INT_MIN;int ans=0;
        for(int i =0;i<n;i++){
            d1=sqrt(double(dim[i][0]*dim[i][0])+double(dim[i][1]*dim[i][1]));
            if(maxi<d1){maxi=d1;ans=(dim[i][0]*dim[i][1]);}
            else if(maxi==d1){ans=max(ans,dim[i][0]*dim[i][1]);}
        }
        return ans;
    }
};