class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
       
        if (s.length() < t.length()) return "";

        std::vector<int> target_count(128, 0); 
        std::vector<int> window_count(128, 0);

        for (char c : t) {
            target_count[c]++;
        }

        int required = 0;
        for (int i = 0; i < 128; ++i) {
            if (target_count[i] > 0) required++;
        }

        int formed = 0;
        int left = 0, right = 0;
        int min_len = INT_MAX;
        int min_left = 0;

        while (right < s.length()) {
            char c = s[right];
            window_count[c]++;

            if (target_count[c] > 0 && window_count[c] == target_count[c]) {
                formed++;
            }

          
            while (left <= right && formed == required) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_left = left;
                }

                char left_char = s[left];
                window_count[left_char]--;
                if (target_count[left_char] > 0 && window_count[left_char] < target_count[left_char]) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        return min_len == INT_MAX ? "" : s.substr(min_left, min_len);
    }
};
