//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    sort(arr, arr+n);
    
    pair<int, int> res;
    vector<int> v;
    
    int l1=-1, r1=n;
    
    while(r1>l1+1) {
        int mid = (l1+r1)/2;
        
        if(arr[mid] > x) {
            r1 = mid;
        } else {
            l1 = mid;
        }
    }
    
    if(l1!=-1)
    v.push_back(arr[l1]);
    else v.push_back(-1);
    
    int l2=-1, r2=n;
    
    while(r2>l2+1) {
        int mid = (l2+r2)/2;
        
        if(arr[mid] < x) {
            l2 = mid;
        } else {
            r2 = mid;
        }
    }
    
    if(r2!=n)
    v.push_back(arr[r2]);
    else v.push_back(-1);
    
    res = make_pair(v[0], v[1]);
    
    return res;
    
    
}