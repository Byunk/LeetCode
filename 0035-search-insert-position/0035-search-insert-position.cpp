class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start, end, mid;
        int ans = -1;
        start = 0;
        end = nums.size()-1;
        while (start <= end) {
            cout << start << " " << end << "\n";
            if (start == end && nums[start] != target) {
                if (target < nums[start]) {
                    ans = start;
                } else {
                    ans = start+1;
                }
                break;
            }
            mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                ans = mid;
                break;
            } else if (nums[mid] < target) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        if (ans == -1) {
            ans = start;
        }
        return ans;
    }
};