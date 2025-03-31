class Solution {
    public long putMarbles(int[] weights, int k) {
        int n = weights.length;
        if (k == 1) return 0; 
        List<Integer> pairSums = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            pairSums.add(weights[i] + weights[i + 1]);
        } 
        Collections.sort(pairSums);      
        long minScore = 0, maxScore = 0;
        for (int i = 0; i < k - 1; i++) {
            minScore += pairSums.get(i);
            maxScore += pairSums.get(n - 2 - i);
        }  
        return maxScore - minScore;
    }
}