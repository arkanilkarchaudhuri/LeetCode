class Solution:
    def triangleType(self, a: List[int]) -> str:
        return ('none','equilateral','isosceles','scalene')[(2*max(a)<sum(a))*len({*a})]