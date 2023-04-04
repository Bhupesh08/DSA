class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        
        if(s == t) return s;
        
        if(t.size() > s.size()) return res;
        
        unordered_map<char, int> freq;
        for (char c : t) {
            freq[c]++;
        }
        int count = freq.size();
        
        int i = 0, j = 0;
        string window;
        int minLen = INT_MAX;
        
        while (j < s.size()) {
            if (freq.count(s[j])) {
                freq[s[j]]--;
                if (freq[s[j]] == 0) {
                    count--;
                }
            }
            window.push_back(s[j]);
            
            while (i <= j && count == 0) {
                if (window.size() < minLen) {
                    minLen = window.size();
                    res = window;
                }
                if (freq.count(s[i])) {
                    freq[s[i]]++;
                    if (freq[s[i]] == 1) {
                        count++;
                    }
                }
                window.erase(window.begin());
                i++;
            }
            j++;
        }
        return res;
    }
};
