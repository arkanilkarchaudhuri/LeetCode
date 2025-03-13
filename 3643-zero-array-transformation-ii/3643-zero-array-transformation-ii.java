class Solution {
    public int minZeroArray(int[] nums, int[][] queries) {
        int n = nums.length;
        if(Arrays.stream(nums).allMatch(x -> x == 0)) {
            return 0;
        }
        int left = 1, right = queries.length;
        if (!isPossibleAllZero(right, nums, queries)) {
            return -1;
        }
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (isPossibleAllZero(mid, nums, queries)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private boolean isPossibleAllZero(int k, int[] num, int[][] queries) {
        int n = num.length;
        int[] diff = new int[n + 1];
        for (int i = 0; i < k; i++) {
            int left = queries[i][0], right = queries[i][1], val = queries[i][2];
            diff[left] += val;
            diff[right + 1] -= val;
        }
        int currentVal = 0;
        for (int i = 0; i < n; i++) {
            currentVal += diff[i];
            if (currentVal < num[i]) {
                return false;
            }
        }
        return true;
    }
}