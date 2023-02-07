//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        int row_start = 0;
        int row_end = n-1;
        int col_start = 0;
        int col_end = m-1;
        
        vector<int> spiral;
        
        while(row_start<=row_end && col_start<=col_end) {
            
            for(int col=col_start; col<= col_end; col++) {
                spiral.push_back(a[row_start][col]);
            } row_start++;
        
            for(int row=row_start; row<=row_end; row++) {
                spiral.push_back(a[row][col_end]);
            } col_end--;
        
            for(int col=col_end; col>=col_start; col--) {
                spiral.push_back(a[row_end][col]);
            } row_end--;
        
            for(int row=row_end; row>=row_start; row--) {
                spiral.push_back(a[row][col_start]);
            } col_start++;
            
        }
        
        return spiral[k-1];
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends