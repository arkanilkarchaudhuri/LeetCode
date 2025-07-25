class Solution:
    def maxSum(self, nums: List[int]) -> int:
        maxNum = max(nums)
        if maxNum < 0:
            return maxNum
        result =  set()
        for num in nums:
            if num > 0 and num not in result:
                result.add(num)
        return sum(result)
        yeah
        