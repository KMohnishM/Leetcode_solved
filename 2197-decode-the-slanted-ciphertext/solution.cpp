class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;

        int n = encodedText.size();
        int cols = n / rows;

        vector<vector<char>> mat(rows, vector<char>(cols));
        
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = encodedText[k++];
            }
        }

        string ans = "";
        for (int j = 0; j < cols; j++) {
            int i = 0, col = j;
            while (i < rows && col < cols) {
                ans += mat[i][col];
                i++;
                col++;
            }
        }
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};
