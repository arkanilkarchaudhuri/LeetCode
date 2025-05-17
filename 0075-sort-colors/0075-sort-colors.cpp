class Solution {
public:
    static void sortColors(vector<int>& a) {
        const int n = a.size();
        uint16_t m[3] = {0};

        for (int i = 0; i < n; ++m[a[i++]]);

        fill(a.begin(), a.begin() + m[0], 0);
        fill(a.begin() + m[0], a.begin() + m[0] + m[1], 1);
        fill(a.begin() + m[0] + m[1], a.end(), 2);
    }
};