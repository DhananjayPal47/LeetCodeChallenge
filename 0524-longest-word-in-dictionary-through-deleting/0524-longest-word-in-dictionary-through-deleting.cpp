class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == s.size();
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        
        sort(dictionary.begin(), dictionary.end(),
             [](const string& a, const string& b) {
                 if (a.size() != b.size()) {
                     return a.size() > b.size();
                 }
                 return a < b;
             });

        for (const string& word : dictionary) {
            if (isSubsequence(word, s)) {
                return word;
            }
        }

        return "";
    }
};