class Solution:
    def addOperators(self, s: str, target: int) -> List[str]:
        def backtrack(i, path, resultSoFar, prevNum):
            if i == len(s):
                if resultSoFar == target:
                    ans.append(path)
                return

            for j in range(i, len(s)):
                if j > i and s[i] == '0': break  
                num = int(s[i:j + 1])
                if i == 0:
                    backtrack(j + 1, path + str(num), resultSoFar + num, num)  
                else:
                    backtrack(j + 1, path + "+" + str(num), resultSoFar + num, num)
                    backtrack(j + 1, path + "-" + str(num), resultSoFar - num, -num)
                    backtrack(j + 1, path + "*" + str(num), resultSoFar - prevNum + prevNum * num, prevNum * num)  

        ans = []
        backtrack(0, "", 0, 0)
        return ans