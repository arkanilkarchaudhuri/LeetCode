class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 0;
        ans = pow(n, 2) + pow(n - 1, 2);
        return ans;
    }
};