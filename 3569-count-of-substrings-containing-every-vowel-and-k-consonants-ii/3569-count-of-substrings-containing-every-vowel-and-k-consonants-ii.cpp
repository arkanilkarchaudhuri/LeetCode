class Solution {
public:
    bool checkVowel(int a){
        return(a == 0 || a == 4 || a == 8 || a == 14 || a == 20);
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        vector<int> check(21,0);
        long long ans = 0;
        int vc = 0;
        int cc = 0;
        int i = 0;
        int j = 0;
        int m = 0;
        while(i < n){
            while(i < n && (vc != 5 || cc != k)){
                int a = word[i] - 'a';
                if(a == 0 || a == 4 || a == 8 || a == 14 || a == 20){
                    check[a]++;
                    if(check[a] == 1) vc++;
                }else{
                    cc++;
                }
                i++;
                while(cc > k){
                    int a = word[j] - 'a';
                    if(a == 0 || a == 4 || a == 8 || a == 14 || a == 20){
                        check[a]--;
                        if(check[a] == 0) vc--;
                    }else{
                        cc--;
                    }
                    j++;
                }
            }
            if(cc == k && vc == 5){
                if(m < i){
                    m = i;
                    while(m < n && checkVowel(word[m] - 'a')){
                        m++;
                    }
                }
                int cnt = m - i + 1;
                while(vc == 5 && cc == k){
                    ans += cnt;
                    int a = word[j] - 'a';
                    if(a == 0 || a == 4 || a == 8 || a == 14 || a == 20){
                        check[a]--;
                        if(check[a] == 0) vc--;
                    }else{
                        cc--;
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};
