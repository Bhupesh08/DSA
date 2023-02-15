class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
       
        for (int i = num.size() - 1; i >= 0 && k > 0; --i) {
            num[i] += k;
            k = num[i] / 10;
            num[i] %= 10;
        }
        
        while (k > 0) {
            num.insert(num.begin(), k % 10);
            k /= 10;
        }
        
        return num;
    
    }
};



//         int n = num.size();
        
//         vector<int> res;
//         stack<int> st;
        
//         long long sum = 0;
        
//         for(int i=0; i<n; i++) {
//             sum += num[i] * pow(10, (n-1)-i);
//         }
        
//         long long toConvert = sum + k;
        
        
//         while(toConvert!=0) {
//             int last_digit = toConvert % 10;
//             toConvert /= 10;
//             st.push(last_digit);
//         }
        
//         while(!st.empty()) {
//             int digit = st.top();
//             st.pop();
//             res.push_back(digit);
//         }
        
//         return res;