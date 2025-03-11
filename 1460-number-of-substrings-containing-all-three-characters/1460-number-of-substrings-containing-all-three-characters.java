class Solution {
    public int numberOfSubstrings(String s) {
        int[] freq = new int[3]; // 'a' -> 0, 'b' -> 1, 'c' -> 2
        int left = 0, ans = 0;

        for (int right = 0; right < s.length(); right++) {
            freq[s.charAt(right) - 'a']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                ans += s.length() - right;
                freq[s.charAt(left) - 'a']--;
                left++;
            }
        }

        return ans;
    }
}