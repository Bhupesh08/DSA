class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        
        //Edge case 1
        if(s == t) return s;
        
        //Edge case 2
        if(t.size() > s.size()) return res;
        
        //Creating the initial required hashmap using string t
        unordered_map<char, int> freq;
        for (char c : t) {
            freq[c]++;
        }
        //count to keep track of the characters which are ACTIVELY present in the hashmap
        int count = freq.size();
        
        //Let the Sliding window algo begin
        int i = 0, j = 0;
        string window;
        int minLen = INT_MAX;
        
        while (j < s.size()) {
            //if the element that j is pointing to is present in the hashmap
            if(freq.count(s[j])) {
                freq[s[j]]--;
                
                if (freq[s[j]] == 0) count--;
            }
            
            //Push the element in the string
            window.push_back(s[j]);
            
            //Incase we have found a string that could well possibly be our answer.
            while(i <= j && count == 0) {
                //Checking the substring size before updating the result
                //we only update if the size is less than the previously updated substring's size
                if (window.size() < minLen) {
                    minLen = window.size();
                    res = window;
                }
                
                //checking if we could further decrease the size of the found substring
                if (freq.count(s[i])) {
                    freq[s[i]]++;
                    //In case the freq[s[i]] doesnt become 1, it means we had that element as faltu and 
                    //count is still 0
                    if (freq[s[i]] == 1) count++;
                }
                //gotta remove the first element anyhoo whether present or not present in hashmap
                window.erase(window.begin());
                i++;
            }
            
            j++;
        }
        
        return res;
    }
};
