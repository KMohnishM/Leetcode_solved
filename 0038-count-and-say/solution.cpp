class Solution {
public:
    string countAndSay(int n) {

        string s = "1";
        for(int i = 2; i <= n; i++) {

            string temp = "";
            int cnt = 1;

            for(int j = 1; j < s.size(); j++) {

                if(s[j] == s[j-1]) {
                    cnt++;
                }
                else {
                    temp += to_string(cnt);
                    temp += s[j-1];
                    cnt = 1;
                }
            }
            temp += to_string(cnt);
            temp += s.back();

            s = temp;
        }

        return s;
    }
};
