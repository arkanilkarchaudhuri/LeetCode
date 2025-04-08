class Solution {
    func minimumOperations(_ nums: [Int]) -> Int {
        var sett = Set<Int>(), i = nums.count-1
        while i>=0 {
            guard !sett.contains(nums[i]) else { return i/3 + 1 }
            sett.insert(nums[i])
            i-=1
        }
        return 0
    }
}