class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        vector<int> max_left;
        vector<int> max_right(n);
        
        int maxi_left = 0;
        for(int i=0; i<n; i++) {
            max_left.push_back(maxi_left);
            
            maxi_left = max(maxi_left, height[i]);
        }
        //for(int x: max_left) cout << x << " ";
        
        int maxi_right = 0;
        for(int i=n-1; i>=0; i--) {
            max_right[i] = maxi_right;
            
            maxi_right = max(maxi_right, height[i]);
        }
        
        //for(int x: max_right) cout << x << " "; 
        
        vector<int> v;
        
        for(int i=0; i<n; i++) {
            v.push_back(min(max_left[i], max_right[i])-height[i]);    
        }
        
        int res = 0;
        for(int i=0; i<n; i++) {
            if(v[i] > 0) res += v[i];
        }
        
        return res;
    }
};