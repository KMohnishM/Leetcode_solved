class Solution {
public:
    string ans = "";
    int count = 0;

    void dfs(string &curr, int n, int k) {
        if(curr.length() == n) {
            count++;
            if(count == k) ans = curr;
            return;
        }

        for(char c : {'a','b','c'}) {
            if(!curr.empty() && curr.back() == c) continue;

            curr.push_back(c);
            dfs(curr, n, k);
            curr.pop_back();

            if(!ans.empty()) return;
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        dfs(curr, n, k);
        return ans;
    }
};
