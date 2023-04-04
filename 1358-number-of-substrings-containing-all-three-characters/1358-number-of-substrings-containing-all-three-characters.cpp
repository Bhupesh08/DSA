class Solution {
// private:
//     int atMost(vector<int> nums, int k) {
        
//         int res = 0; 
//         int i = 0, j = 0;
        
//         vector<int> freq(3);
        
//         while(j < nums.size()) {
            
//             k -= freq[nums[j]]++ == 0 ? 1 : 0;
            
//             while (k < 0) {
//                 k += freq[nums[i++]]-- == 1 ? 1 : 0;
//             }
            
//             res += j - i + 1;
//             j++;
//         }
        
        
//         return res;
//     }

public:
    int numberOfSubstrings(string s) {
        
//         vector<int> arr(s.size());
//         for (int i = 0; i < s.length(); i++) {
//             arr[i] = s[i] - 'a';
//         }
        
//         return atMost(arr, 3) - atMost(arr, 2);
        
        int left = 0, right = 0, count = 0;
    unordered_map<char, int> freq;
    while (right < s.size()) {
        freq[s[right]]++;
        right++;
        while (freq['a'] && freq['b'] && freq['c']) {
            count += s.size() - right + 1;
            freq[s[left]]--;
            left++;
        }
    }
    return count;
    }
};