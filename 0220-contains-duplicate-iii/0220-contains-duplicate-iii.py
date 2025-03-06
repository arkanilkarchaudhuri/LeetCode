class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], indexDiff: int, valueDiff: int) -> bool:
        buckets = {} 
        valueDiff +=1
        
        for idx, curVal in enumerate(nums):
            bucketId = curVal // valueDiff 
            if bucketId in buckets: return True 
            for i in (bucketId - 1, bucketId + 1):
                if i in buckets:
                    if abs(buckets[i] - curVal) < valueDiff:
                        return True
            buckets[bucketId] = curVal
            if idx >= indexDiff:
                removeVal = nums[idx - indexDiff]
                del buckets[removeVal//valueDiff]

        return False