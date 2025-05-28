class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], 
                       edges2: List[List[int]], k: int) -> List[int]:

        def dfs(node: int, level: int, par: int, count = 1) -> int:

            if level < k:
                for chd in graph[node]:
                    if chd == par: continue
                    count += dfs(chd, level + 1, node)
            return count


        n, m, mx = len(edges1) + 1, len(edges2) + 1, 0
        if k == 0: return [1] * n

        graph = [[] for _ in range(m)]

        for u, v in edges2:
            graph[u].append(v)
            graph[v].append(u)

        for node in range(m):
            mx = max(mx, dfs(node, 1, -1))

        graph = [[] for _ in range(n)]
        for u, v in edges1:
            graph[u].append(v)
            graph[v].append(u)

        return [dfs(node, 0, -1) + mx for node in range(n)]