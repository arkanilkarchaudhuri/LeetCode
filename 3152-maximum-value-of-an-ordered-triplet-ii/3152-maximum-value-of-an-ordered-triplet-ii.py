class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        max_result = 0
        max_num = 0
        max_diff = 0
        for num in nums:
            max_result = max(max_result, max_diff * num)
            max_diff = max(max_diff, max_num - num)
            max_num = max(max_num , num)
        return max_result
        