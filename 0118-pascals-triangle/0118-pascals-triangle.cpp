class Solution {
//     #define ll long long
//     private:
    
//     ll fact(int n)
// {
//       if(n==0)
//       return 1;
//     ll ans = 1;
//     for (int i = 2; i <= n; i++)
//         ans = ans * i;
//     return ans;
// }
    
//     int combination(int n, int r) {
//         return fact(n)/(fact(n-r)*fact(r));
//     }

    public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res;
        
        for(int i=0; i<numRows; i++) {
            vector<int> v(i+1, 1); //initialising with value = 1, so that we dont have to alter first and last element in each iteration
            
            for(int j=1; j<i; j++) {
                v[j] = res[i-1][j-1] + res[i-1][j];
            }
            
            res.push_back(v);
        }
        
        
        
        return res;
        

       
        //         vector<vector<int>> res;
        
//         for(int i=1; i<=numRows; i++) {
//             int n = i;
//             vector<int> v;
//             int r = 0;
            
            
//             while(n!=0) {
//                 v.push_back(combination(i-1, r));
//                 r++;
//                 n--;
//             }
            
//             res.push_back(v);
//         }
        
        
//         return res;
        
    }
};