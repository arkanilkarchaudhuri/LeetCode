class Solution {

    public int minCapability(int[] nums, int k) {
        int mid = 0;
        int count;
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        int ans = Integer.MAX_VALUE;

        for (int num : nums) {
            max = Math.max(num, max);
            min = Math.min(num, min);
        }

        while (min <= max) {
            mid = min + ((max - min) >> 1);
            count = 0;
            for (int i = 0; i < nums.length; i++) {
                if (mid >= nums[i]) {
                    count++;
                    i++;
                }
            }
            if (count >= k) {
                ans = mid;
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }
        return ans;
    }
}