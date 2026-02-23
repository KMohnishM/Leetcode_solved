class Solution {
public:
    void backtrack(string digits, int index, string current, vector<string>& res, unordered_map<char, string>& m) {
    if (index == digits.length()) {
        res.push_back(current);
        return;
    }
    string letters = m[digits[index]];
    for (char c : letters) {
        backtrack(digits, index + 1, current + c, res, m);
    }
}
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> combination;
        vector<string> result;
        char a='a';
        for(char i='2';i<='9';i++){
           int k;
           if(i=='7'||i=='9'){
            k=4;
           }
           else{k=3;}
           for(int j=0;j<k;j++){
               combination[i]+=a; 
               a=a+1;
           }
        }
        backtrack(digits,0,"",result,combination);
        return result;
    }
};
