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



