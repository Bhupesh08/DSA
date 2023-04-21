class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        vector<int> max_left;
        vector<int> max_right(n);
        
        //To get the tower with the highest height in left subarray
        int maxi_left = 0;
        for(int i=0; i<n; i++) {
            max_left.push_back(maxi_left);
            
            maxi_left = max(maxi_left, height[i]);
        }
        
    
        //To get the tower with the highest height in right subarray
        int maxi_right = 0;
        for(int i=n-1; i>=0; i--) {
            max_right[i] = maxi_right;
            
            maxi_right = max(maxi_right, height[i]);
        }
        
     
        //To get the water stored by index
        vector<int> v;
        for(int i=0; i<n; i++) {
            v.push_back(min(max_left[i], max_right[i])-height[i]);    
        }
        
        int res = 0;
        for(int i=0; i<n; i++) {
            //Only consider when the amount of water > 0
            if(v[i] > 0) res += v[i];
        }
        
        return res;
    }
};