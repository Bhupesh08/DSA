class Solution {
    
private:
    void helper(string s, string op, set<string> &unique) {
        if(s.empty()) {
            unique.insert(op);
            return;
        }
        
        string op1 = op;
        string op2 = op;
        
        if(s[0] >= 48 && s[0] <= 57) {
            op1.push_back(s[0]);
            op2.push_back(s[0]);
            s.erase(s.begin() + 0);
        } 
        
        else if(s[0] >= 65 && s[0] <= 90) {
            op1.push_back(tolower(s[0]));
            op2.push_back(s[0]);
            s.erase(s.begin() + 0);
        }
        
        else {
            op1.push_back(toupper(s[0]));
            op2.push_back(s[0]);
            s.erase(s.begin() + 0);
        }
        
        helper(s, op1, unique);
        helper(s, op2, unique);
        
        
    }
    
public:
    vector<string> letterCasePermutation(string s) {
        set<string> unique;
        
        string op;
        
        helper(s, op, unique);
        
        vector<string> res;
        
        for(auto it: unique) {
            res.push_back(it);
        }
        
        return res;
    }
};