# @param {Integer[]} nums
# @param {Integer} lower
# @param {Integer} upper
# @return {Integer}
def count_fair_pairs(nums, lower, upper)
  nums.sort!
  count = -> (lim, l: 0, u: nums.size - 1, cnt: 0) {
      nums[l] + nums[u] < lim ? (cnt, l = cnt + u - l, l + 1) : u -= 1 while l <= u; cnt }
  count[upper + 1] - count[lower]
end