class Solution {
private: 
    //The given value of k is good when koko can eat all the bananas within given h hrs
    //So the fxn good(speed) return true when it is possible to eat all the bananas within h hrs else returns false
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
        
        //finding the max element to decide the upper limit of the search space
        long long max = INT_MIN;
        for(int i=0; i<n; i++) {
            if(piles[i] > max) {
                max = piles[i];
            }
        }
        
        //edge case
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