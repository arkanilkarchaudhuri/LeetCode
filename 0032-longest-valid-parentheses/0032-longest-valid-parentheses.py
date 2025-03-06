class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = [-1]  # Initialize stack with -1 to handle edge cases
        max_length = 0
        
        for i, char in enumerate(s):
            if char == '(':
                stack.append(i)  # Push the index of '(' onto the stack
            else:  # char == ')'
                stack.pop()  # Pop the last index from the stack
                
                if not stack:
                    # If stack is empty, push the current index as the new base
                    stack.append(i)
                else:
                    # Calculate the length of the valid substring
                    max_length = max(max_length, i - stack[-1])
        
        return max_length
        