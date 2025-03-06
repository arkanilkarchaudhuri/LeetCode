class Solution {
public:
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