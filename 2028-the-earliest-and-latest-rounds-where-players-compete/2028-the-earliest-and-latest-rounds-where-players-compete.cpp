class Solution {
    int minVal = INT_MAX, maxVal = INT_MIN, fp, sp, np;
    bool dp[28][28][28];
    void earliestAndLatestUtil (int mask, int round, int i, int j, int l, int m, int r) {
        if (i >= j) {
            earliestAndLatestUtil(mask, round + 1, 0, np, l, m, r);
        }
        else if ((mask & (1 << i)) == 0) {
            earliestAndLatestUtil(mask, round, i + 1, j, l , m, r);
        }
        else if ((mask & (1 << j)) == 0) {
            earliestAndLatestUtil(mask, round, i, j - 1, l, m , r);
        }
        else if (i == fp && j == sp) {
            minVal = min(minVal, round);
            maxVal = max(maxVal, round);
        }
        else if (!dp[l][m][r]) {
            dp[l][m][r] = true;
            if (i != fp && i != sp) {
                earliestAndLatestUtil(mask ^ (1 << i), round, i + 1, j - 1, l - (i < fp), m - ((i > fp) && (i < sp)), r - (i > sp));
            }
            if (j != fp && j != sp) {
                earliestAndLatestUtil(mask ^ (1 << j), round, i + 1, j - 1, l - (j < fp), m - ((j > fp) && (j < sp)), r - (j > sp));
            }
        }
    }
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        fp = firstPlayer - 1;
        sp = secondPlayer - 1;
        np = n - 1;
        int mask = (1<<n) - 1;
        memset(dp, false, sizeof(dp));
        earliestAndLatestUtil(mask, 1, 0, np, fp, sp -fp - 1, np - sp);
        return {minVal, maxVal};
    }
};