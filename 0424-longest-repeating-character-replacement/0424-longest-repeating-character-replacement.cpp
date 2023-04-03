class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(26);
        int i=0, j=0;
        int res = 0;
        
        while(j < s.size()) {
            v[s[j] - 'A']++;
            
            if((j-i+1) - *max_element(v.begin(), v.end()) <= k) {
                res = max(res, j-i+1);
                j++;
            }
            
            else if((j-i+1) - *max_element(v.begin(), v.end()) > k) {
                while((j-i+1) - *max_element(v.begin(), v.end()) > k) {
                    v[s[i] - 'A']--;
                    i++;
                }
                
                j++;
            }
        }
    
        return res;
    }
};