class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        DIR = [0, 1, 0, -1, 0]
        m, n = len(matrix), len(matrix[0])
        
        outDegree = [[0] * n for _ in range(m)]
        for r in range(m):
            for c in range(n):
                for i in range(4):
                    nr, nc = r + DIR[i], c + DIR[i+1]
                    if nr < 0 or nr == m or nc < 0 or nc == n or matrix[nr][nc] <= matrix[r][c]: continue
                    outDegree[r][c] += 1
            
        q = deque([])
        for r in range(m):
            for c in range(n):
                if outDegree[r][c] == 0:
                    q.append([r, c])
                    
        level = 0
        while q:
            level += 1
            for _ in range(len(q)):
                r, c = q.popleft()
                for i in range(4):
                    nr, nc = r + DIR[i], c + DIR[i+1]
                    if nr < 0 or nr == m or nc < 0 or nc == n or matrix[nr][nc] >= matrix[r][c]: continue
                    outDegree[nr][nc] -= 1
                    if outDegree[nr][nc] == 0:
                        q.append([nr, nc])
                    
        return level