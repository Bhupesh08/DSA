//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    
	    
        int mini = INT_MAX;
        int index;
        
        if(n==1) {
            return 0;
        }
        
        //Handling the edge case when the array is rotated n number of times and we got the original array back.
        if(arr[0] < arr[n-1]) {
            return 0;
        }
        
        int l = -1, r = n;
        
        while(r>l+1) {
            int mid = l - (l-r)/2;
            
            //mid lies in left sorted array
            if(arr[mid] >= arr[0]) {
                l = mid;
            //mid lies in right sorted array
            } else {
                mini = min(mini, arr[mid]);
                index = mid;
                r = mid;
            }
            
            
        }
        
        
        return index;
        
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends