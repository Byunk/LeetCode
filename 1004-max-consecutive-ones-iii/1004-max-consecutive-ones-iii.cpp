class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        
        int cnt = 0;
        int maxCnt = 0;
        while (r < n) {
            if (nums[r] == 1) {
                ++cnt; ++r;
            }
            else if (k > 0) {
                ++cnt; ++r; --k;
            }
            else if (nums[l] == 1) {
                --cnt; ++l;
            }
            else {
                --cnt; ++k; ++l;
            }
            
            if (cnt > maxCnt) {
                maxCnt = cnt;
            }
        }
        return maxCnt;
    }
};