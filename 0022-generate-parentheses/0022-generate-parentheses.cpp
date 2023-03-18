class Solution {
private:
    void helper(int open, int close, string op, vector<string> &res) {
        if(open == 0 && close == 0) {
            res.push_back(op);
            return;
        }
        
        
        if(open != 0) {
            string op1 = op;
            op1.push_back('(');
            helper(open-1, close, op1, res);
        }
        
        
        if(close > open && close != 0) {
            string op2 = op;
            op2.push_back(')');
            helper(open, close-1, op2, res);
        }
    }
    
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        
        int open = n;
        int close = n;
        
        string op;
        
        helper(open, close, op, res);
        
        return res;
    }
};