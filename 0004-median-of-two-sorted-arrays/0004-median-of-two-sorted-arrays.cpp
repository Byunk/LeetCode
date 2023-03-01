class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            nums1.swap(nums2);
        }
        int total = nums1.size() + nums2.size();
        int half = total / 2;

        int l = 0;
        int r = nums1.size() - 1;
        while (true) {
            int i = l + r;
            int j = half - i - 2;

            int left1 = i >= 0 ? nums1[i] : INT_MIN;
            int right1 = i+1 < nums1.size() ? nums1[i+1] : INT_MAX;
            int left2 = j >= 0 ? nums2[j] : INT_MIN;
            int right2 = j+1 < nums2.size() ? nums2[j+1] : INT_MAX;

            if (left1 <= right2 && left2 <= right1) {
                //odd
                if (total%2 == 1) {
                    return min(right1, right2);
                } else {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            } else if (left1 > right2) {
                r = i-1;
            } else {
                l = i+1;
            }
        }
    }
};