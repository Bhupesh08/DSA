class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        vector<pair<int, int>> v;
        int m = matrix.size();
        int n = matrix[0].size();


        //Iterate over the all the whole matrix, If zero found, push its coordinates into vector
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j]==0) {
                    v.push_back({i, j});
                }
            }
        }



        //iterating over the pushed coordinates. 
        for(auto it: v) {
            int row = it.first;  //get row from coordinate
            int col = it.second; //get col from coordinate

            //Iterate over the row and make the non-zero elements as zero.
            for(int j=0; j<n; j++) {
                if(matrix[row][j]!=0) {
                    matrix[row][j] = 0;
                }
            }

            //Iterate over the column and make the non-zero elements as zero.
            for(int i=0; i<m; i++) {
                if(matrix[i][col]!=0) {
                    matrix[i][col] = 0;
                }
            }

        }
        
    }
};