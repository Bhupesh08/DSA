//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        
        int i = n-1;
        
        stack<int> st;
        st.push(a[i]);
        
        vector<int> res;
        
        while(i > 0) {
            int j = i-1;
            
            while(a[j] < a[i] && j >=0) {
                j--;
            }
            
            
            if(j>=0)
            {
                st.push(a[j]);
                // i = j;
                
            }
            
            i = j;
        }
        
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        
        
        return res;
        
        
        
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends