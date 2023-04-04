class Solution {
private:
    int atMost(vector<int> arr, int k) {
        
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
    int numberOfSubstrings(string s) {
        
        vector<int> arr(s.size());
        for (int i = 0; i < s.length(); i++) {
            arr[i] = s[i] - 'a';
        }
        
        return atMost(arr, 3) - atMost(arr, 2);
        
        
    }
};



// int left = 0, right = 0, count = 0;
//     unordered_map<char, int> freq;
//     while (right < s.size()) {
//         freq[s[right]]++;
//         right++;
//         while (freq['a'] && freq['b'] && freq['c']) {
//             cout << s.size() - right + 1 << endl;
//             count += s.size() - right + 1;
//             freq[s[left]]--;
//             left++;
//         }
//     }
//     return count;