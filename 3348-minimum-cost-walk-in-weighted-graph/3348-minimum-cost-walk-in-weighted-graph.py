class UnionFind:
    def __init__(self, n: int):
        self.parent = [*range(n)]
        self.rank = [1] * n
        self.weight = [-1] * n
               
    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x: int, y: int, w: int) -> None:
        x, y = self.find(x), self.find(y)
        if x == y:
            self.weight[x] &= w
            return
        if self.rank[x] < self.rank[y]:
            self.parent[x] = y
            self.weight[y] &= self.weight[x] & w
        else:
            self.parent[y] = x
            self.weight[x] &= self.weight[y] & w
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1
            

class Solution:
    def minimumCost(self, n: int, edges: List[List[int]], query: List[List[int]]) -> List[int]:
        uf = UnionFind(n)
        for u, v, w in edges:
            uf.union(u, v, w)
        ans = []
        for u, v in query:
            u, v = uf.find(u), uf.find(v)
            ans.append(uf.weight[u] if u == v else -1)
        return ans