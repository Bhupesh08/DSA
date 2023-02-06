class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> res;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int l = 0;
        int r = n;
        int b = m;
        int t = 0;
        
        
        while(l<r && t<b) {
            
            //get every element in top row
            for(int j=l; j<r; j++) {
                res.push_back(matrix[t][j]);
            } t++;
            
            //get every element in right col
            for(int i=t; i<b; i++) {
                res.push_back(matrix[i][r-1]);
            } r--;
            
            //run on a column and a row matrix to see why this is necessary
            //most important part of the code. Please Remember!!!!
            if(!(l<r && t<b)) {
                break;
            }
            
            //get every element in bottom col
            for(int j=r-1; j>=l; j--) {
                res.push_back(matrix[b-1][j]);
            } b--;
            
            //get every element in left col
            for(int i=b-1; i>=t; i--) {
                res.push_back(matrix[i][l]);
            } l++;
            
        }
        
        return res;
        
    }
};