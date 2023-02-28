class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    
    // if (strs.empty()) {
    //     return "";
    // }
    
    int n = strs.size();
    string res;
    
    for(int i=0; i<strs[0].size(); i++) {
        char c = strs[0][i];
        
        for(int j=1; j<n; j++) {
            if (i >= strs[j].size() || strs[j][i] != c) {
                return res;
            }
        }
        
        res.push_back(c);
    }
    
    return res;
}

};

//         int n = strs.size(); // 3
//         string res;
        
//         if(n==1) {
//             return strs[0];
//         }
        
//         for(int i=0; i<strs[0].size(); i++) {
//             char c = strs[0][i];
            
//             int j = 0;
//             while(strs[j][i] == c) {
//                 j++;
//             }
//             res.push_back(c);
//         }
        
        
        
        
//         return res;
//     }