class Solution {
private:
int atMostkDifferentIntegers(vector<int> &arr, int k) {
    
    int i = 0, j = 0;
    int res = 0;
    map<int, int> hashmap;

    while(j < arr.size()) {
        hashmap[arr[j]]++;
        
        //hashmap.size() gives us the value of the number of unique integers.
        while(hashmap.size() > k) {
            hashmap[arr[i]]--;
            if(hashmap[arr[i]] == 0) hashmap.erase(arr[i]);
            i++;
        }
        
        //Now we have got us a nice subarray which is a ideal one.
        //out of that ideal subarray, we can now have (j-i+1) ideal subarrays.
        //Notice how the result is incremented by the size of the window.
        res += j-i+1;
        j++;
    } 

    return res;
}

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostkDifferentIntegers(nums, k) - atMostkDifferentIntegers(nums, k-1); 
    }
};
