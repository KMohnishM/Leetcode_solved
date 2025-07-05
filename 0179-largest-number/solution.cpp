class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for (int x : nums) s.push_back(to_string(x));

        sort(s.begin(), s.end(), [](string& a, string& b) {
            return a + b > b + a;
        });

        if (s[0] == "0") return "0";

        string result;
        for (auto& str : s) result += str;

        return result;
    }
};
