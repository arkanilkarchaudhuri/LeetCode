class Solution {
    fun buildArray(nums: IntArray): IntArray {
        for (i in 0 until nums.size) {
            nums[nums[i] and 0xFFFF] = nums[nums[i] and 0xFFFF] or ((i + 1) shl 16)
        }

        for (i in 0 until nums.size) {
            nums.placeAt(nums[i] shr 16, nums[i] and 0xFFFF)
        }

        for (i in 0 until nums.size) {
            nums[i] = nums[i] and 0xFFFF
        }

        return nums
    }

    private fun IntArray.placeAt(index: Int, value: Int) {
        if (index == 0) return
        val old = this[index - 1]
        this[index - 1] = value
        placeAt(old shr 16, old and 0xFFFF)
    }
}