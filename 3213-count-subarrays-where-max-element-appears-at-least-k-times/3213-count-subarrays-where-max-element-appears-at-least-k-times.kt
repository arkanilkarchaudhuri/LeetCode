class Solution {
    fun countSubarrays(nums: IntArray, k: Int): Long {
        var element = 0
        for (num in nums) {
            element = maxOf(element, num)
        }
        var appears = 0
        var result = 0L
        var left = 0
        for (right in nums.indices) {
            if (nums[right] == element) {
                appears++
            }
            while (appears >= k) {
                if (nums[left] == element) {
                    appears--
                }
                left++
            }
            result += left
        }
        return result
    }
}