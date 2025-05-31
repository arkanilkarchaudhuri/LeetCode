class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int count=0,n=board.size(),k=0;
        vector<int>val(n*n,0);
        for (int i=n-1;i>=0;i--) {
            if((n-1-i)%2==0){
                for(int j=0;j<n;j++){
                    val[k]=board[i][j];
                    k++;
                }
            }else{
                for(int j=n-1;j>=0;j--){
                    val[k]=board[i][j];
                    k++;
                }
            }
        }
        queue<int>Q;
        Q.push(0);
        set<int>visit;
        visit.insert(0);
        while(!Q.empty()){
            int d=Q.size();
            for(int i=0;i<d;i++){
                int p=Q.front();
                if(p==(n*n-1))return count;
                for(int t=1;t<=6;t++){
                    int next=p+t;
                    if(next>=n*n)break;
                    int destination=0;
                    if(val[next]==-1)
                    destination=next;
                    else destination=val[next]-1;
                    if(visit.find(destination)==visit.end()) {
                        visit.insert(destination);
                        Q.push(destination);
                    }
                }
                Q.pop();
            }
            count++;
        }
        return -1;
    }
};