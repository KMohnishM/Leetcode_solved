class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> stk;
        string result;

        for (char ch : s) {
            if (ch == '(') {
                if (!stk.empty()) {
                    result += ch; 
                }
                stk.push(ch);
            } else { 
                stk.pop(); 
                if (!stk.empty()) {
                    result += ch; 
                }
            }
        }
        
        return result;
    }
};

