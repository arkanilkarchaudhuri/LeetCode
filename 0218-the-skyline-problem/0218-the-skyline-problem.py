from sortedcontainers import SortedList
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        if len(buildings) == 0: 
            return []
        
        buildings.sort(key=lambda v: v[2])
        pos, height = [0], [0]
        for left, right, h in buildings: 
            i = bisect_left(pos, left)
            j = bisect_right(pos, right)
            height[i:j] = [h, height[j-1]]
            pos[i:j] = [left, right]
        print(height, pos)
        res = []
        prev = 0
        for v, h in zip(pos, height): 
            if h != prev:
                res.append([v,h]) 
                prev = h
                
        return res