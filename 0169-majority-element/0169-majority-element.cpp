class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();
//         int res;
//         map<int, int> mpp;

//         for(int i=0; i<n; i++) {
//             mpp[nums[i]]++;
//         }

//         for(auto it=mpp.begin(); it!=mpp.end(); it++) {
//             if(it->second > n/2) {
//                 res = it->first;
//             }
//         }

//         return res;
        
        
        int candidate = INT_MIN;
        int life = 0;
        
        for(int i=0; i<n; i++) {
            if(life==0) {
                candidate = nums[i];
            }
            
            if(nums[i]==candidate) {
                life++;
            } else {
                life--;
                
            }
        }
        
        return candidate;
    }
};