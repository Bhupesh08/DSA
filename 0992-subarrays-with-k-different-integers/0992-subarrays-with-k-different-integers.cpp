class Solution {
private:
int kDistinctSubarrays(vector<int> &arr, int k) {
    
    int i = 0, j = 0;
    int res = 0;
    map<int, int> hashmap;

    while(j < arr.size()) {
        hashmap[arr[j]]++;

        while(hashmap.size() > k) {
            hashmap[arr[i]]--;
            if(hashmap[arr[i]] == 0) hashmap.erase(arr[i]);
            i++;
        }

        res += j-i+1;
        j++;
    } 

    return res;
}

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return kDistinctSubarrays(nums, k) - kDistinctSubarrays(nums, k-1); 
    }
};