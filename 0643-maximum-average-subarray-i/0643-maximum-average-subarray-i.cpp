class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        
        // define two pointers
        int l = 0, r = k;
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int maxSum = sum;
        
        while (r < n) {
            sum += nums[r] - nums[l];
            if (sum > maxSum) {
                maxSum = sum;
            }
            ++r; ++l;
        }
        return (double) maxSum / k; 
    }
};