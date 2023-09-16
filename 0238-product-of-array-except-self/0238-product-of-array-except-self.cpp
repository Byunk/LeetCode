class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProduct, rightProduct, ret;
        
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                leftProduct.push_back(nums[i]);
                continue;
            }
            leftProduct.push_back(leftProduct[i-1] * nums[i]);
        }
        
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                rightProduct.push_back(nums[n-1 - i]);
                continue;
            }
            rightProduct.push_back(rightProduct[i-1] * nums[n-1 - i]);
        }
        
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                ret.push_back(rightProduct[n-1 - (i+1)]);
                continue;
            } else if (i == n-1) {
                ret.push_back(leftProduct[i-1]);
                continue;
            }
            ret.push_back(leftProduct[i-1] * rightProduct[n-1 - (i+1)]);
        }
        return ret;
    }
};