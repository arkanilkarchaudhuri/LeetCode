class Solution {
public:
    int longestNiceSubarray(vector<int>& a) {
        const int n = a.size();
        int count = 1;
        for (int i = 0, j = 1, s = a[0]; j < n;) {
            if (s & a[j]) {
                s ^= a[i++];
            } else {
                s |= a[j++];
                count = max(count, j - i);
            }
        }
        return count;
    }
};