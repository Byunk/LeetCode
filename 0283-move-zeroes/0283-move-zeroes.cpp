class Solution {
private:
    void moveToBack(vector<int>& nums, int idx) {
        int len = nums.size();
        while (idx != len-1) {
            swap(nums[idx], nums[idx+1]);
            ++idx;
        }
    }
    
    bool isFollowingZeros(vector<int>& nums, int idx) {
        for (int i = idx; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                return false;
            }
        }
        return true;
    }
    
public:
    void moveZeroes(vector<int>& nums) {
        int p = 0;
        int len = nums.size();
        while (p != len-1) {
            if (isFollowingZeros(nums, p)) {
                return;
            }
            
            if (nums[p] == 0) {
                moveToBack(nums, p);
            } else {
                ++p;
            }
        }
    }
};