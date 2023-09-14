class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // find the greatest number of candies
        int l = candies.size();
        int great = 0;
        for (int i = 0; i < l; ++i) {
            if (candies[i] > great) {
                great = candies[i];
            }
        }
        
        int threshold = great - extraCandies;
        vector<bool> ret;
        for (int i = 0; i < l; ++i) {
            if (candies[i] < threshold) {
                ret.push_back(false);
            } else {
                ret.push_back(true);
            }
        }
        
        return ret;
    }
};