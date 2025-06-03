class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {

        int tcandy=0, n=candies.size();
        vector<bool>visited(n,0);
        queue<int>q;

        for(int x:initialBoxes)q.push(x);

        while(!q.empty()){
            int curbox=q.front();
            q.pop();

            if(status[curbox]==1 && !visited[curbox]){
                tcandy+=candies[curbox];
                candies[curbox]= -1;
            }

            for(int key:keys[curbox]){
                status[key]=1;
                if(visited[key] && candies[key]!= -1){
                    visited[key]=false;
                    q.push(key);
                }               
            }

            for(int box:containedBoxes[curbox]){
                if(candies[box]!=0 && !visited[box])q.push(box);
            }

            visited[curbox]=true;
        }
        return tcandy;
    }
};