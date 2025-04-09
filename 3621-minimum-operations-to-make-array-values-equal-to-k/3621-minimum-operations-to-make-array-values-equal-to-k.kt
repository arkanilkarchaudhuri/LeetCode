class Solution {
    fun minOperations(nums: IntArray, k: Int): Int {
        var count = -1
        val seen = hashSetOf<Int>()
        var minimum = Integer.MAX_VALUE
        for(i in 0..nums.size-1){
            if(!seen.contains(nums[i])){
                count++
                minimum = minOf(minimum, nums[i])
                seen.add(nums[i])
            }
        }

        if(minimum<k){
            return -1
        }
        
        if(minimum == k){
            return count
        }

        return count+1
    }
}