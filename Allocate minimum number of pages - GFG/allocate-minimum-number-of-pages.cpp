//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    private: 
    bool isGood(int nums[],int n, int k, int maxSum) {
        int subarr = 0;
        int sum = 0;
        
        for(int i=0; i<n; i++) {
            sum += nums[i];
            if(sum > maxSum) {
                subarr++;
                sum = nums[i];
            }
        }
        
        if(sum <= maxSum) {
            subarr++;
        }
        
        return subarr <= k;
    }
    
    
    
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        
        //edge case number 1
        if(N < M) {
            return -1;
        }
        
        //edge case number 2
        if(M==1) {
            return accumulate(A, A + N, 0);
        }
        
        //edge case number 3
        if(M == N) {
            return *max_element(A, A + N);
        }
        
        int l = *max_element(A, A + N) - 1;
        int r = accumulate(A, A + N, 0);
        
        while(r > l+1) {
            int mid = l - (l-r)/2;
            
            if(isGood(A, N, M, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        
        return r;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends