//Solution 1
class Solution {
public:
    string customSortString(string order, string s) {
    unordered_map<char, int> custom_order;
    for (int i = 0; i < order.size(); ++i) {
        custom_order[order[i]] = i;
    }

    sort(s.begin(), s.end(), [&](char a, char b) {
        return custom_order[a] < custom_order[b];
    });

    return s;
    }
};
//Solution 2
class Solution {
public:
    string customSortString(string order, string s) {
        string custom;
        vector<int> freq(26, 0);
        for (char c: s) {
            freq[c - 'a']++;
        }
        for (char c: order) {
            while (freq[c - 'a']) {
                custom += c;
                freq[c - 'a']--;
            }
        }
        for (int i = 0; i < 26; i++) {
            while (freq[i]) {
                custom += i + 'a';
                freq[i]--;
            }
        }
        return custom;
    }
};
