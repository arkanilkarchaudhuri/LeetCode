def rec(nums, i, curr, ans)
    if i >= nums.length
        ans[0] += curr
        return
    end
    rec(nums, i + 1, curr, ans)
    rec(nums, i + 1, curr ^ nums[i], ans)
end

# @param {Integer[]} nums
# @return {Integer}
def subset_xor_sum(nums)
    ans = [0]
    rec(nums, 0, 0, ans)
    return ans[0]
end