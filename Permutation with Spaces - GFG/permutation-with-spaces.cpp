//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    private:
    void permutationHelper(string s, string &op, vector<string> &ans) {
        if(s.empty()) {
            ans.push_back(op);
            return;
        }
        
        string op1 = op;
        string op2 = op;
        
        //Adding the character with space
        op1.push_back(32);
        op1.push_back(s[0]);
        //Adding the character without space
        op2.push_back(s[0]);
        
        s.erase(s.begin() + 0);
        
        permutationHelper(s, op1, ans);
        permutationHelper(s, op2, ans);
        
    }
    
    
    
public:

    vector<string> permutation(string S){
        vector<string> ans;
        
        string op;
        
        //Adding the first character before passing the given string
        //Because we dont want a space before that character
        op.push_back(S[0]);
        S.erase(S.begin() + 0);
        
        
        permutationHelper(S, op, ans);
        
        return ans;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends