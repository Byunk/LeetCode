class Solution {
public:
    string dict[10] = {"", "", "abc", "def", "ghi", "jkl", "nmo", "pqrs", "tuv", "wxyz"};
    string given;
    vector<string> ans;

    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return ans;
        }
        given = digits;
        dfs(0, "");
        return ans;
    }

    void dfs(int idx, string str) {
        if (idx == given.size()) {
            ans.push_back(str);
            return;
        }

        int i = given[idx] - '0';
        string letters = dict[i];
        for (auto c : letters) {
            dfs(idx+1, str + c);
        }
    }
};