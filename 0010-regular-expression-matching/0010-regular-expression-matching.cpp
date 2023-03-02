class Solution {
public:
    bool result;
    string ss;
    string pp;

    bool isMatch(string s, string p) {
        ss = s;
        pp = p;
        dfs(0, 0);
        return result;
    }

    void dfs(int i, int j) {
        if (i >= ss.size() && j >= pp.size()) {
            result = true;
            return;
        } else if (j == pp.size()) {
            return;
        }

        bool isMatch = i < ss.size() && (ss[i] == pp[j] || pp[j] == '.');

        if (j < pp.size()-1 && pp[j+1] == '*') {
            if (!isMatch) {
                dfs(i, j+2);
            } else {
                // use *
                dfs(i+1, j);

                // do not use *
                dfs(i, j+2);
            }            
        } else if (isMatch) {
            dfs(i+1, j+1);
        } else {
            return;
        }
    }
};