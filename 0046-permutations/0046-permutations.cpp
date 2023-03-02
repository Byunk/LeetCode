class Solution {
public:
    vector<vector<int>> result;
    int visited[6];

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> permutation;
        dfs(nums, permutation);
        return result;
    }

    void dfs(vector<int>& nums, vector<int>& permutation) {
        if (permutation.size() == nums.size()) {
            result.push_back(permutation);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            permutation.push_back(nums[i]);
            dfs(nums, permutation);
            permutation.pop_back();
            visited[i] = false;
        }
    }
};