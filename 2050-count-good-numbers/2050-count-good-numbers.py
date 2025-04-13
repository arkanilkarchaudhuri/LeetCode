class Solution:
    M = 10**9 + 7

    def binpow(self, a: int, b: int) -> int:
        a %= self.M
        res = 1
        while b > 0:
            if b & 1:
                res = res * a % self.M
            a = a * a % self.M
            b >>= 1
        return res

    def countGoodNumbers(self, n: int) -> int:
        even_positions = (n + 1) // 2
        odd_positions = n // 2
        result = self.binpow(5, even_positions) * self.binpow(4, odd_positions) % self.M
        return result