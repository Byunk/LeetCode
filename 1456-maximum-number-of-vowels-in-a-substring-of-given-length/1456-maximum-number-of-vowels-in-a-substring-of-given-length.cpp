class Solution {
private:
    bool isVowel(char c) {
        char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
        return find(vowels, vowels+5, c) != vowels+5;
    }
    
public:
    int maxVowels(string s, int k) {
        // define two pointers
        int l = 0, r = 0;
        int cnt = 0;
        int maxCnt = 0;
        for (auto c : s) {
            if (r-l < k) {
                if (isVowel(s[r])) ++cnt;
                if (cnt > maxCnt) maxCnt = cnt;
                ++r;
                continue;
            }
            if (isVowel(s[r])) ++cnt;
            if (isVowel(s[l])) --cnt;
            if (cnt > maxCnt) maxCnt = cnt;
            ++r; ++l;
        }
        return maxCnt;
    }
};