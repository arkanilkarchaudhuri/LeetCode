class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        
        if(left==right)
            return {-1,-1};

        if(left<=1)
            return {2,3};

        
        int prev=-10,retPrev=-1,retCurr=-1;
        int diff=1e9;

        for(int num=left;num<=right;num++)
        {
            int curr=num;

            for(int i=2;i*i<=num;i++)
            {
                if(num%i==0)
                {
                    curr=-1;
                    break;
                }
            }

            if(curr!=-1&&prev>0)
            {
                if(curr-prev<diff)
                {
                    retPrev=prev,retCurr=curr;

                    diff=curr-prev;

                    if(diff==2)
                        return {retPrev,retCurr};
                }

                    
            }

            if(curr!=-1)
                prev=curr;
        }

        return {retPrev,retCurr};

    }
};