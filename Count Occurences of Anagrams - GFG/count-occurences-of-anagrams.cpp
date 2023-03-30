//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    
	    unordered_map<char, int> mpp;
	    int count;
	    int res = 0;
	    int i=0, j=0;
	    
	    //creating the hashmap where the character is stored with its count
	    for(char x: pat) {
	        mpp[x]++;
	    }
	    
	    //storing total number of characters present in the hashmap
	    //helps in decreasing the time complexity as we dont have to iterate the whole hashmap again and again
	    count = mpp.size();
	    
	    //Declaring window size
	    int K = pat.size();
	    
	    //Here comes the template of sliding window
	    while(j < txt.size()) {
	        
	        //Do some task/calculation
	        if(mpp.count(txt[j])) {
	            mpp[txt[j]]--;
	            
	            if(mpp[txt[j]] == 0) count--;
	        }
	        
	        //window size not achieved
	        if(j-i+1 < K) j++;
	        
	        //Window size is acheived
	        else if(j-i+1 == K) {
	            
	            //Answer found based on task/calculation
	            if(count == 0) res++;
	            
	            //Undo the calculation
	            if(mpp.count(txt[i])) {
	                mpp[txt[i]]++;
	                
	                if(mpp[txt[i]] == 1) {
	                    count++;
	                }
	            } 
	            
	            //Slide the window
	            i++;
	            j++;
	        }
	    
	        
	    }
	    
	    return res;
	    
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends