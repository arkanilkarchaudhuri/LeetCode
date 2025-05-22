class Solution(object):
    def maxRemoval(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: int
        """
        n = len(nums)
        qz = len(queries)
        
        qEnd = [[] for _ in range(n)]
        for i in range(qz):
            l, r = queries[i]
            qEnd[l].append(r)
        
        max_heap = []
        cntQ = [0] * (n + 1)
        dec = 0
        
        for i in range(n):
            x = nums[i]
            dec += cntQ[i]
            
            for r in qEnd[i]:
                heapq.heappush(max_heap, -r)
            
            while x > dec and max_heap and -max_heap[0] >= i:
                r = -heapq.heappop(max_heap)
                cntQ[r + 1] -= 1
                dec += 1

            if x > dec:
                return -1
        
        return len(max_heap)