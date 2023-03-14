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
    vector<string> num;

    int sumNumbers(TreeNode* root) {
        preOrder(root, "");

        int ans = 0;
        for (int i = 0; i < num.size(); i++) {
            ans += stoi(num[i]);
        }
        return ans;
    }

    void preOrder(TreeNode* node, string n) {
        if (node == nullptr) {
            return;
        }
        
        char val = node->val + '0';
        if (node->left == nullptr && node->right == nullptr) {
            n = n + val;
            num.push_back(n);
            return;
        }

        preOrder(node->left, n + val);
        preOrder(node->right, n + val);
    }
};