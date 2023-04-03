class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(26);   //26 because we want to store 26 uppercase alphabets
        int i=0, j=0;   
        int res = 0;
        
        while(j < s.size()) {
            //Calculation: we are storing the frequency of a particular alphabet
            v[s[j] - 'A']++;
            
            //The number of elements we would like to replace = size of the window - the most frequently occuring element
            //Condition: (The number of elements we would like to replace <= allowed replacements)
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