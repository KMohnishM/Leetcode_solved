#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int len = n + m - 1;

        vector<char> word(len, '?');
        vector<bool> fixed(len, false);

       
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                        fixed[i + j] = true;
                    } else {
                        return "";
                    }
                }
            }
        }

       
        for (int i = 0; i < len; i++) {
            if (word[i] == '?') word[i] = 'a';
        }

       
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;

                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool broken = false;

                    for (int j = m - 1; j >= 0; j--) {
                        int pos = i + j;

                        if (fixed[pos]) continue; 

                        char original = word[pos];

                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c != str2[j]) {
                                word[pos] = c;
                                broken = true;
                                break;
                            }
                        }

                        if (broken) break;
                        word[pos] = original;
                    }

                    if (!broken) return "";
                }
            }
        }

        return string(word.begin(), word.end());
    }
};
