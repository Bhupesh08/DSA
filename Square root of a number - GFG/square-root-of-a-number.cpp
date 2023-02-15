//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // vector<long long> v(x);
        
        // long long i = 1;
        // while(i<=x) {
        //     v[i-1]=i;
        //     i++;
        // }
        
        if(x==1) {
            return 1;
        }
        
        long long l = 0, h = x;    //Initial search space like we can be sure that the sq root will lie between (1, x)
        
        while(h>l+1) {
            int mid = l - (l-h)/2;
            
            if(pow(mid, 2)==x) {   //if(mid^2==given number) means mid is only its sq root
                return mid;
            }
            
            else if(pow(mid, 2) > x) {  //if(mid^2 > given number) means searching right of mid is a waste of time and we should decrease the search space by only focusing on left of the mid
                h = mid;
            }
            
            else {        //focus on the right side of the mid
                l = mid;
            }
        }
        
        return l;    //dekh bhai agar equal hai toh answer upar wali IF STATMENT hi de degi nahi toh l will point to the real number whose square is just less than x 
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends