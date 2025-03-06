class Solution {
public:
    bool isNumber(std::string s) {
        int n = s.size();
        int i = 0;

        while (i < n && s[i] == ' ') i++;
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;

        bool isNumeric = false;
        
        while (i < n && isdigit(s[i])) {
            isNumeric = true;
            i++;
        }
        
   
        if (i < n && s[i] == '.') {
            i++;
            while (i < n && isdigit(s[i])) {
                isNumeric = true;
                i++;
            }
        }
        

        if (isNumeric && i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            isNumeric = false;
            
  
            if (i < n && (s[i] == '+' || s[i] == '-')) i++;
            
   
            while (i < n && isdigit(s[i])) {
                isNumeric = true;
                i++;
            }
        }
        

        while (i < n && s[i] == ' ') i++;

        return isNumeric && i == n;
    }
};