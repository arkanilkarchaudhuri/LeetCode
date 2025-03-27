class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        d=Counter(nums)
        r=d.most_common()[0][0]

        n1=0
        n2=len(nums)
        f1=0
        f2=d[r]

        for i in range(len(nums)):
            n1+=1
            n2-=1
            if nums[i]==r:
                f1+=1
                f2-=1
            if f1*2>n1 and f2*2 >n2:
                return i
        return -1