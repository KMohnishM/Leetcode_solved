class Solution {
public:
    string sortVowels(string s) {
        vector<int> positions;
        vector<char> vowels;
        
        auto isVowel = [](char c) {
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
                   c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
        };
        
        
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                positions.push_back(i);
                vowels.push_back(s[i]);
            }
        }
        
        
        sort(vowels.begin(), vowels.end());
        
        
        for (int k = 0; k < positions.size(); k++) {
            s[positions[k]] = vowels[k];
        }
        
        return s;
    }
};

