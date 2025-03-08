class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        l=0
        r=k
        length=len(blocks)
        mn=1000000
        while r<=length:
            op=blocks[l:r].count("W")
            if op<mn:
                mn=op
            l+=1
            r+=1
        return mn