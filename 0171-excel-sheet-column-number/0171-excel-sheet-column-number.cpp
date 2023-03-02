class Solution {
public:
    int titleToNumber(string columnTitle) {
        const int n = columnTitle.size();
        int ans = 0;
        int factor = 1;
        for (int i = n-1; i >= 0; i--) {
            int k = columnTitle[i] - 'A' + 1;
            ans += k * factor;
            if (i != 0) {
                factor *= 26;
            }
        }
        return ans;
    }
};