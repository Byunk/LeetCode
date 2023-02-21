class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            auto it = s.find(nums[i]);
            if (it != s.end()) {
                s.erase(it);
            } else {
                s.insert(nums[i]);
            }
        }
        auto it = s.begin();
        return *it;
    }
};