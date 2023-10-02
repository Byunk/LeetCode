class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        int maxA = -1;
        
        // Initialize two pointers
        int l = 0; int r = n-1;
        while (l < r) {
            int lh = height[l];
            int rh = height[r];
            
            int width = r - l;
            int height = min(lh, rh);
            int area = width * height;
            
            if (area > maxA) {
                maxA = area;
            }
            
            // Move lower limit to possible higher element
            if (lh <= rh) {
                ++l;
            } else {
                --r;
            }
        }
        return maxA;
    }
};