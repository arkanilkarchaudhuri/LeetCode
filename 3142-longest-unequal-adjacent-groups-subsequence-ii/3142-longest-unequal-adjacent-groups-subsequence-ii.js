/**
 * @param {string[]} words
 * @param {number[]} groups
 * @return {string[]}
 */
var getWordsInLongestSubsequence = function(words, groups) {
    function hamming(s, t){
        if (s.length !== t.length){
            return false;
        }
        let diff = 0;
        for (let i = 0; i < s.length; i++){
            if (s[i] !== t[i]){
                diff++;
                if (diff > 1){
                    return false;
                }
            }
        }
        return diff === 1;
    }
    const n = words.length;
    const dp = new Array(n).fill(1);
    const nxt = new Array(n).fill(-1);
    let max_len = 0, start = -1;

    for (let i = n - 1; i >= 0; i--){
        for (let j = i + 1; j < n; j++){
            if (groups[i] !== groups[j] && hamming(words[i], words[j])){
                if (dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    nxt[i] = j;
                }
            }
        }
        if (dp[i] > max_len){
            max_len = dp[i];
            start = i;
        }
    }
    const res = [];
    while (start !== -1){
        res.push(words[start]);
        start = nxt[start];
    }
    return res;
    
};