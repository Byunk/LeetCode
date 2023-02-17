/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;

    int minDiffInBST(TreeNode* root) {
        DFS(root);
        sort(v.begin(), v.end());
        int diff = 100001;
        for (int i = 0; i < v.size()-1; i++) {
            if (diff > abs(v[i] - v[i+1])) {
                diff = abs(v[i] - v[i+1]);
            }
        }
        return diff;
    }

    void DFS(TreeNode* node) {
        if (!node) {
            return;
        }
        v.push_back(node->val);
        DFS(node->left);
        DFS(node->right);
    }
};