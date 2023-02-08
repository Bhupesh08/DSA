class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        int numRows = rowIndex + 1;
        vector<vector<int>> res;
        
        for(int i=0; i<numRows; i++) {
            vector<int> v(i+1, 1); 
            
            for(int j=1; j<i; j++) {
                v[j] = res[i-1][j-1] + res[i-1][j];
            }
            
            res.push_back(v);
        }
        
        
        
        return res[rowIndex];
        
    }
};