//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
private:
    bool isGood(vector<int> &stalls, int n, int k, int minDis) {
        
        int prevCow = 0; // index of the stall where the last cow is put
        int cow = 1; //Count of cow is made 1 as 1 cow is put at the very first stall 
        
        //This for loop returns the number of cow that can be put in the stalls
        for(int i=1; i<n; i++) {
            if(stalls[i] - stalls[prevCow] >= minDis) {
                cow++;
                prevCow = i;
            }
            //return cow;
        }
        
        //if number of cow that can be put is greater than required, then also return true 
        //true because agar zyada put kardi, matlab yeh toh common sense huhi ki required toh put kar hi sakte hai
        return cow >= k; 
    }


public:

    int solve(int n, int k, vector<int> &stalls) {
        
        sort(stalls.begin(), stalls.end());
    
        int l = 0;
        int r = stalls[n-1] + 1;
        
        while(r > l+1) {
            int mid = l - (l-r)/2;
            
            if(isGood(stalls, n, k, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        
        return l;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends