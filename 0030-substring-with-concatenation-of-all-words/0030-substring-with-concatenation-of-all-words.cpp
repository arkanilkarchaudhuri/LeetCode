class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        int word_len = words[0].size();
        int num_words = words.size();
        int total_len = word_len * num_words;
        
        // Create a frequency map for words
        unordered_map<string, int> word_count;
        for (const auto& word : words) {
            word_count[word]++;
        }
        
        // Check each possible starting position
        for (int i = 0; i < word_len; ++i) {
            unordered_map<string, int> current_count;
            int left = i;
            int right = i;
            int count = 0;
            
            while (right + word_len <= s.size()) {
                // Get the current word
                string word = s.substr(right, word_len);
                right += word_len;
                
                if (word_count.find(word) != word_count.end()) {
                    current_count[word]++;
                    count++;
                    
                    // If count of current word exceeds the required count, move left pointer
                    while (current_count[word] > word_count[word]) {
                        string left_word = s.substr(left, word_len);
                        current_count[left_word]--;
                        count--;
                        left += word_len;
                    }
                    
                    // Check if we have found all words in the current window
                    if (count == num_words) {
                        result.push_back(left);
                    }
                } else {
                    // Reset everything if the word is not in the word list
                    current_count.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        
        return result;
    }
};