class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        int n = nums1.size();
        
        int res = 0;
        
        map<int, int> hashMap;
        
        //For filling our hash map
        for(int k=0; k<n; k++) {
            for(int l=0; l<n; l++) {
                hashMap[-nums3[k]-nums4[l]]++;
            }
        }
        
        //For checking if the sum exits in the hashmap or not
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(hashMap.count(nums1[i]+nums2[j])) {
                    res+=hashMap[nums1[i]+nums2[j]];
                }
            }
        }
        
        return res;
    }
};