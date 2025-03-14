class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) return {};
        std::vector<std::string> phone_map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::vector<std::string> combinations;
        backtrack(0, digits, "", combinations, phone_map);
        return combinations;
    }
    
private:
    void backtrack(int index, const std::string& digits, std::string path, std::vector<std::string>& combinations, const std::vector<std::string>& phone_map) {
        if (index == digits.size()) {
            combinations.push_back(path);
            return;
        }
        std::string possible_letters = phone_map[digits[index] - '2'];
        for (char letter : possible_letters) {
            backtrack(index + 1, digits, path + letter, combinations, phone_map);
        }
    }
};