class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool isVisited[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                isVisited[i][j] = false;
            }
        }
        vector<int> visit;

        int remained = m*n;
        int r, c;
        r = c = 0;
        isVisited[r][c] = true;
        visit.push_back(matrix[r][c]);
        remained--;
        while (true) {
            if (remained == 0) {
                break;
            }

            // row-wise
            while (true) {
                if (c+1 >= n || isVisited[r][c+1]) {
                    break;
                }
                c++;
                isVisited[r][c] = true;
                visit.push_back(matrix[r][c]);
                remained--;
            }

            if (remained == 0) {
                break;
            }

            // column-wise
            while (true) {
                if (r+1 >= m || isVisited[r+1][c]) {
                    break;
                }
                r++;
                isVisited[r][c] = true;
                visit.push_back(matrix[r][c]);
                remained--;
            }

            if (remained == 0) {
                break;
            }

            // row-wise
            while (true) {
                if (c-1 < 0 || isVisited[r][c-1]) {
                    break;
                }
                c--;
                isVisited[r][c] = true;
                visit.push_back(matrix[r][c]);
                remained--;
            }

            if (remained == 0) {
                break;
            }

            // column-wise
            while (true) {
                if (r-1 >= m || isVisited[r-1][c]) {
                    break;
                }
                r--;
                isVisited[r][c] = true;
                visit.push_back(matrix[r][c]);
                remained--;
            }

            if (remained == 0) {
                break;
            }
        }
        return visit;
    }
};