class Solution {
public:
    bool isHappy(int n) {
        set<long long> hashSet;
        
        long long sum = 0;
        while(n!=0) {
            int lastDigit = n % 10;
            sum += (lastDigit * lastDigit);
            n =  n / 10;
            
            if(n == 0) {
                // cout << sum << " " << endl;
                if(hashSet.count(sum)) {
                    return false;
                } else {
                    hashSet.insert(sum);
                }
                
                
                if(sum==1) {
                    return true;
                } else {
                    n = sum;
                    sum = 0;
                }
            }
            
        }
        
        return true;
    }
};