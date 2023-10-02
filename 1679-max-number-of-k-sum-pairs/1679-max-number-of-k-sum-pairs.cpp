class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ret = 0;
        
        // sort nums
        sort(nums.begin(), nums.end());
        
        // two pointers
        int l = 0; int r = n-1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == k) {
                ++ret;
                ++l;
                --r;
            } else if (sum > k) {
                --r;
            } else {
                ++l;
            }
        }
        return ret;
    }
};