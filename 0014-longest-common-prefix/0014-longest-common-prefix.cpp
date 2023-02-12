class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        for (int i = 0; i < strs.size(); i++) {
            if (i == 0) {
                prefix = strs[i];
                continue;
            }

            if (prefix.size() > strs[i].size()) {
                prefix = prefix.substr(0, strs[i].size());
            }

            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] != prefix[j]) {
                    prefix = prefix.substr(0, j);
                    break;
                }
            }
        }
        return prefix;
    }
};