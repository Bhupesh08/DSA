class Solution {
private: 
    
    bool good(vector<int>& bloomDay, int m, int k, int days) {
    int n = bloomDay.size();
        
    // vector<int> vec(n, 0);
    // for(int i=0; i<n; i++) {
    //     if(bloomDay[i] <= days) {
    //         vec[i] = 1;
    //     }
    // }

    int count = 0, guchha = 0;

    for(int i=0; i<n; i++) {

        if(bloomDay[i] <= days) {
            count++;
        } else {
            count = 0;
        }

        if(count==k) {
            guchha++;
            count = 0;
        }
    }

    if(guchha >= m) {
        return true;
    }

    return false;
}

    
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        //Edge case when it is not possible to make the required number of bouquets.
        long long floReq = (long long)m*(long long)k;
        if(floReq > bloomDay.size()) {
            return -1;
        }
        
        //To find the upper limit of the search space.
        long long maxi = INT_MIN;
        for(int i=0; i<bloomDay.size(); i++) {
            if(bloomDay[i] > maxi) {
                maxi = bloomDay[i];
            }
        }
        
        //Binary Search begins.
        long long l = 0;
        long long r = maxi + 1;
        
        while(r > l+1) {
            int mid = l - (l-r)/2;
            
            if(good(bloomDay, m, k, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        
        return r;
        
    }
};