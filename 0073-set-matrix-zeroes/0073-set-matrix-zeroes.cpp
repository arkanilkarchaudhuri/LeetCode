class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isFirstRowZero=false,isFirstColumnZero=false;
        for (int i = 0; i < matrix.size(); i++)
            {
                if(matrix[i][0]==0)
                    { 
                        isFirstColumnZero=true;
                        break;
                    }
            }
         for (int i = 0; i < matrix[0].size(); i++)
            {
                if(matrix[0][i]==0)
                    {
                        isFirstRowZero=true;
                        break;
                    }
            }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[0][j] == 0 ||
                    matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(isFirstColumnZero)
        {
            for (int i = 0; i < matrix.size(); i++) 
            {
                matrix[i][0]=0;
            }
        }
        if(isFirstRowZero)
        {
            for (int i = 0; i < matrix[0].size(); i++) 
            {
                matrix[0][i]=0;
            }
        }
    }
};