class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n - 1; i++)
        {
            arr[i + 1] = arr[i] ^ arr[i + 1];
        }
        
        return arr[n- 1];
    }
};