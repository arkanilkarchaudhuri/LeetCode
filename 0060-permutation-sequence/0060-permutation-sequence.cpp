class Solution {
public:
    std::string getPermutation(int n, int k) {
        std::vector<int> numbers;
        std::vector<int> factorial(n, 1);
        
        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
        }
        for (int i = 1; i < n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
        k--;
        
        std::string result;
        
        for (int i = n; i >= 1; i--) {
            int index = k / factorial[i - 1];
            result += std::to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k %= factorial[i - 1];
        }
        
        return result;
    }
};