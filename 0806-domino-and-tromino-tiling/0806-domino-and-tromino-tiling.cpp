class Solution {
public:
#define md 1000000007
    int numTilings(int n) {
        vector<long long> v(1001, 0);

        v[1] = 1;
        v[2] = 2;
        v[3] = 5;
        
        for(int i = 4; i <= n; i++)
            v[i] = (2 * v[i-1] + v[i-3]) % md;
        
    return v[n];
    }
};