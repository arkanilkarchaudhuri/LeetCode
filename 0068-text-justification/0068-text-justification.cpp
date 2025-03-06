class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLength = words[i].length();
            int last = i + 1;

            while (last < n && lineLength + words[last].length() + (last - i) <= maxWidth) {
                lineLength += words[last].length();
                last++;
            }

            std::string line;
            int gaps = last - i - 1;

            
            if (last == n || gaps == 0) {
                for (int j = i; j < last; ++j) {
                    line += words[j];
                    if (j < last - 1) {
                        line += ' ';
                    }
                }
                line += std::string(maxWidth - line.length(), ' '); 
            } else {
      
                int totalSpaces = maxWidth - lineLength;
                int spacePerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int j = i; j < last; ++j) {
                    line += words[j];
                    if (j < last - 1) {
                        int spacesToApply = spacePerGap + (j - i < extraSpaces ? 1 : 0);
                        line += std::string(spacesToApply, ' ');
                    }
                }
            }
            result.push_back(line);
            i = last; 
        }
        return result;
    }
};