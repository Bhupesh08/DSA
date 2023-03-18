//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
private:
    void helper(int ones, int zeroes, int n, string op, vector<string> &res) {
        if(ones + zeroes == n) {
            res.push_back(op);
            return;
        }
        
        string op1 = op;
        op1.push_back('1');
        helper(ones+1, zeroes, n, op1, res);
        
        if(ones > zeroes) {
            string op2 = op;
            op2.push_back('0');
            helper(ones, zeroes+1, n, op2, res);
        }
        
    }
    
public:	
	vector<string> NBitBinary(int N)
	{
	    vector<string> res;
	    
	    string op;
	    op.push_back('1');
	    
	    helper(1, 0, N, op, res);
	    
	    return res;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends