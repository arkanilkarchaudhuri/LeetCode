class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<int> heights(cols, 0);  
        int max_area = 0;

       
        for (int i = 0; i < rows; ++i) {
           
            for (int j = 0; j < cols; ++j) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
     
            max_area = std::max(max_area, largestRectangleArea(heights));
        }

        return max_area;
    }

private:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> indices;
        int max_area = 0;
        int index = 0;

        while (index < heights.size()) {
           
            if (indices.empty() || heights[index] >= heights[indices.top()]) {
                indices.push(index++);
            } else {
             
                int top_of_stack = indices.top();
                indices.pop();
                int height = heights[top_of_stack];
                int width = indices.empty() ? index : index - indices.top() - 1;
                max_area = std::max(max_area, height * width);
            }
        }

    
        while (!indices.empty()) {
            int top_of_stack = indices.top();
            indices.pop();
            int height = heights[top_of_stack];
            int width = indices.empty() ? index : index - indices.top() - 1;
            max_area = std::max(max_area, height * width);
        }

        return max_area;
    }
};