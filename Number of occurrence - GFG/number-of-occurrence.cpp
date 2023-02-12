//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int res;
	    
	    int l1=-1, r1=n;
	    
	    while(r1>l1+1) {
	        int mid = l1 - (l1-r1)/2;
	        if(arr[mid]<=x) {
	            l1 = mid; //l1 will store maximum element <= target
	        } else {
	            r1 = mid;
	        }
	    }
	    
	    if(arr[l1]!=x) {
	        return 0; //element not present
	    }
	    
	    int l2=-1, r2=n;
	    
	    while(r2>l2+1) {
	        int mid = l2 - (l2-r2)/2;
	        if(arr[mid]<x) {
	            l2 = mid; //l2 will store maximum element < target
	        } else {
	            r2 = mid;
	        }
	    }
	    
	    res = l1-l2;
	    
	    return res;
	    
	    
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends