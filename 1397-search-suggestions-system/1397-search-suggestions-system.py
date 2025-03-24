class Solution:
    def suggestedProducts(self, A: List[str], searchWord: str) -> List[List[str]]:
        A.sort()
        res, cur = [], ''
        for c in searchWord:
            cur += c
            i = bisect.bisect_left(A, cur)
            res.append([w for w in A[i:i+3] if w.startswith(cur)])
        return res