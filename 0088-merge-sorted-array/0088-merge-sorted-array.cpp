class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        //method - 1: merge nums2 with nums1 and then sort nums1
//         int j = 0;
//         for(int i = m; i<m+n; i++) {
//             swap(nums1[i], nums2[j]);
//             j++;
//         }
        
//         sort(nums1.begin(), nums1.end());
        
        
        //method - 2: 
        int i = (m==0) ? 0 : m-1 ;
        int j = n-1;
        int k = m+n-1;
        
        //another kind of edge case 
        if(i==0 && m==0) {
            while(j>=0) {
                swap(nums2[j], nums1[k]);
                k--;
                j--;
            }
            
            return;
        }
        
        while(i >= 0 && j >= 0) {
            
            if(nums2[j] > nums1[i]) {
                swap(nums2[j], nums1[k]);
                k--;
                j--;
            } 
            
            else if(nums1[i] > nums2[j]) {
                swap(nums1[i], nums1[k]);
                k--;
                i--;
                
                //taking care of the edge case:
                if(i<0) {
                    while(j>=0) {
                        swap(nums2[j], nums1[k]);
                        k--;
                        j--;
                    }
                }
            }
            
            else{
                swap(nums1[i], nums1[k]);
                swap(nums1[i], nums2[j]);
                j--; k--;
            }
        
        }
            
            
        
    }
};