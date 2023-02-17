class Solution {
    
private:
    bool good(vector<int>& weights, int days, int capacity) {
        int n = weights.size();
        
        int curWeight = 0;
        int daysTaken = 0;
        
        for(int i=0; i<n; i++) {
            if(curWeight < capacity) {
                
                curWeight += weights[i];
                
                if(curWeight==capacity) {
                    daysTaken++;
                    curWeight = 0;
                }
                
                if(curWeight > capacity) {
                    daysTaken++;
                    curWeight = weights[i];
                }
            }
            
        }
        
        if(curWeight > 0) {
            daysTaken++;
        }
        
        if(daysTaken <= days) {
            return true;
        } 
        
        return false;
        
    }
    
    
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        
        //Calculating the lower and upper limit of initial search space:
        int sum = 0, maxi = INT_MIN;
        for(int i=0; i<n; i++) {
            sum += weights[i];
            if(weights[i] > maxi) {
                maxi = weights[i];
            }
        }
        
        
        //Binary Search begins:
        int l = maxi - 1;
        int r = sum + 1;
        
        while(r > l+1) {
            int mid = l - (l-r)/2;
            
            if(good(weights, days, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        
        return r;
       
        
        
    }
};