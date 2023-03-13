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
    bool ans = true;

    bool isSymmetric(TreeNode* root) {
        inOrderComparison(root->left, root->right);
        return ans;
    }

    void inOrderComparison(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr) {
            return;
        } else if (node1 == nullptr) {
            ans = false;
            return;
        } else if (node2 == nullptr) {
            ans = false;
            return;
        }

        if (node1->val != node2->val) {
            ans = false;
            return;
        }
        inOrderComparison(node1->left, node2->right);
        inOrderComparison(node1->right, node2->left);
    }
};