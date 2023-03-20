class Solution {
public:
    long long powerMod(int a, long long x, int mod) {
        //Base Case
        if(x==0) return 1;
        
        //Hypothesis
        long long ans = powerMod(a, x/2, mod);
        
        //Induction
        ans *= ans;
        ans %= mod;       //Any change in answer means mode to be taken
        if(x%2) ans *= a;
        ans %= mod;       //Any change in answer means mode to be taken
        
        return ans;
    }
    
    int countGoodNumbers(long long n) {
        int mod = 1e9+7;
        
        long long odd = n/2;
        long long even = n - odd;
        
        return (powerMod(5, even, mod) * powerMod(4, odd, mod)) % mod;
    }
};


















// class Solution {
// private:
//     const int MOD = 1000000007;
    
//     int helper(long long n, long long &res) {
//         //Base case
//         if(n==0) {
//             return res*5 % MOD;
//         } 
        
//         //Hypothesis
//         helper(n-1, res);
        
//         //Induction
//         if(n%2 == 0) {
//             res = (res * 4) % MOD;   //No. of prime numbers
//         } else res = (res * 5) % MOD;      //No. of even numbers
        
//         return res;
//     }
    
// public:
//     int countGoodNumbers(long long n) {
//         long long res = 1;
        
//         helper(n, res);
        
//         return res;
//     }
// };
