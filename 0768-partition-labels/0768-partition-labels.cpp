class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> freqs;
        for(char& c : s) {
            freqs[c]++;
        }
        unordered_set<char> sc;
        vector<int> sol;
        int lastIdx = -1;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            sc.insert(c);
            freqs[c]--;
            if(freqs[c] == 0) {
                sc.erase(c);
            }
            if(sc.empty()) {
                sol.push_back(i - lastIdx);
                lastIdx = i;
            }
        }
        return sol;
    }
};