class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        mul=1
        mul2=1
        c=0
        for i in nums :
            mul=mul*i
            if i==0:
                c=c+1
                continue
            mul2=mul2*i
        if c>1:
            return [0]*len(nums)
        for i in range(len(nums)):
            if nums[i]!=0:
                nums[i]=mul//nums[i]
            else:
                nums[i]=mul2
        return nums
                
        
        