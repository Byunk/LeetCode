class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        // Two cases should be considered
        // 1. symmetric case
        // The most frequent symmetric cases can be used on maximum length Palindrome
        // Then even numbers of remained symmetric cases can be used.
        // 2. unsymmetric case
        // only one case whose number of words is odd can be used
        int n = words.size();
        unordered_map<string, int> sym;
        unordered_map<string, int> unsym;
        int num_unsym = 0;

        for (int i = 0; i < n; i++) {
            string s = words[i];
            if (s[0] == s[1]) {
                if (sym.find(s) != sym.end()) {
                    sym[s]++;
                } else {
                    sym[s] = 1;
                }
            } else {
                string reversed = "";
                reversed += s[1];
                reversed += s[0];

                if (unsym.find(reversed) != unsym.end()) {
                    unsym[reversed]--;
                    if (unsym[reversed] == 0) {
                        unsym.erase(reversed);
                    }
                    num_unsym++;
                    continue;
                }

                if (unsym.find(s) != unsym.end()) {
                    unsym[s]++;
                } else {
                    unsym[s] = 1;
                }
            }
        }

        // symmetric case
        int num_sym = 0;
        int num_odd = 0;
        for (auto it : sym) {
            num_sym += it.second;
            if (it.second % 2 == 1) {
                num_odd++;
            }
        }

        if (num_odd > 1) {
            num_sym -= num_odd - 1;
        }

        return 2 * num_sym + 4 * num_unsym;
    }
};