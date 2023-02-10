class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> result;
        for (int i = 0; i < n; i++) {
            bool flag = false;
            int r, c;
            c = i;
            for (int r = 0; r < m; r++) {
                if (grid[r][c] == 1) {
                    if (c == n-1) {
                        flag = true;
                        break;
                    }
                    if (grid[r][c+1] == -1) {
                        flag = true;
                        break;
                    }
                    c++;
                } else {
                    if (c == 0) {
                        flag = true;
                        break;
                    }
                    if (grid[r][c-1] == 1) {
                        flag = true;
                        break;
                    }
                    c--;
                }
            }
            if (flag) {
                result.push_back(-1);
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};