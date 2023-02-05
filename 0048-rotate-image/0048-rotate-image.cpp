class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        //To rotate a matrix by 90 degrees, we need to do TRANSPOSE + REVERSE
        
        int n = matrix.size();
        
        //REVERSE
        reverse(matrix.begin(), matrix.end());
        
        //TRANSPOSE
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        
        
        
        
        
        
    }
};