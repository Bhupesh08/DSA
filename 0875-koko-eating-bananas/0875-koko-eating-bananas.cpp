class Solution {
private: 
    bool good(vector<int>& piles, int h, int k) {
        int n = piles.size();
        double hrs = 0;
        for(int i=0; i<n; i++) {
            int bananas = piles[i]; 
            hrs += ceil((double)bananas/(double)k);
        }

        if(hrs <= h) {
            return true;
        }

        return false;
    }
    

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        
        long long max = INT_MIN;
        for(int i=0; i<n; i++) {
            if(piles[i] > max) {
                max = piles[i];
            }
        }
        
        if(n==h) {
            return max;
        }
        
        long long l = 0;
        long long r = max;;
        
        //yeh method kabhi mat bhulna
        while(r>l+1) {
            int mid = l - (l-r)/2;
            
            if(good(piles, h, mid)) {
                r = mid;
            } else {
                l = mid;
            }
    
        }
        
        return r;
       
    }
};