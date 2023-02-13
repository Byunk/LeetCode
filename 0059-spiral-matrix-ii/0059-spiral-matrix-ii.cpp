class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            vector<int> v(n, 0);
            ans.push_back(v);
        }
        int dc[4] = {1, 0, -1, 0};
        int dr[4] = {0, 1, 0, -1};
        int flag = 0; // index of dc and dr
        int nMove = 1;
        int r = 0;
        int c = 0;
        ans[r][c] = nMove;
        while (true) {
            if (nMove == pow(n, 2)) {
                break;
            }
            int nr = r + dr[flag];
            int nc = c + dc[flag];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || ans[nr][nc] != 0) {
                if (flag == 3) {
                    flag = 0;
                } else {
                    flag++;
                }
                continue;
            }
            ans[nr][nc] = nMove + 1;
            r = nr;
            c = nc;
            nMove++;
        }
        return ans;
    }
};