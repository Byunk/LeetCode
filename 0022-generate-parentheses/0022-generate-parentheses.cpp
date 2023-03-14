class Solution {
public:
    vector<string> ans;

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return ans;
    }

    bool isValid(string s) {
        stack<char> brackets;

        for (char c : s) {
            if (c == '(') {
                brackets.push(c);
            } else {
                if (brackets.empty() || brackets.top() != '(') {
                    return false;
                }
                brackets.pop();
            }
        }
        if (!brackets.empty()) {
            return false;
        }
        return true;
    }

    void dfs(int n, int cnt1, int cnt2, string s) {
        if (s.size() == n * 2) {
            if (isValid(s)) {
                ans.push_back(s);
            }
            return;
        }

        if (cnt1 < n) {
            dfs(n, cnt1 + 1, cnt2, s + '(');
        }
        if (cnt2 < n) {
            dfs(n, cnt1, cnt2 + 1, s + ')');
        }
    }
};