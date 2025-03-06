class Solution:
    def calculate(self, s: str) -> int:
        s = f'({s.replace(" ", "")})'
        f = lambda m: str(sum(map(int, findall(r'[+-]?\d+', m[0]))))
        while '(' in s:
            s = re.sub(r'\([^()]+\)', f, s).replace('--', '+')
        return int(s)