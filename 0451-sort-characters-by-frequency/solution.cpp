#include <string>
#include <unordered_map>
#include <vector>

class Solution {
    using Map = std::unordered_map<char,int>;

    /* -------- merge‑sort helpers -------- */
    void merge(std::vector<char>& a, int l, int m, int r, const Map& freq)
    {
        int n1 = m - l + 1, n2 = r - m;
        std::vector<char> L(a.begin() + l, a.begin() + m + 1);
        std::vector<char> R(a.begin() + m + 1, a.begin() + r + 1);

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            char c1 = L[i], c2 = R[j];

            // compare by descending frequency, break ties by char value
            if (freq.at(c1) > freq.at(c2) ||
                (freq.at(c1) == freq.at(c2) && c1 < c2))
            {
                a[k++] = c1; ++i;
            } else {
                a[k++] = c2; ++j;
            }
        }
        // copy leftovers
        while (i < n1) a[k++] = L[i++];
        while (j < n2) a[k++] = R[j++];
    }

    void mergeSort(std::vector<char>& a, int l, int r, const Map& freq)
    {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        mergeSort(a, l, m, freq);
        mergeSort(a, m + 1, r, freq);
        merge(a, l, m, r, freq);
    }

public:
    std::string frequencySort(std::string s) {
        /* 1. frequency table */
        Map freq;
        for (char c : s) ++freq[c];

        /* 2. merge‑sort the characters */
        std::vector<char> arr(s.begin(), s.end());
        mergeSort(arr, 0, static_cast<int>(arr.size()) - 1, freq);

        /* 3. rebuild string */
        return std::string(arr.begin(), arr.end());
    }
};

