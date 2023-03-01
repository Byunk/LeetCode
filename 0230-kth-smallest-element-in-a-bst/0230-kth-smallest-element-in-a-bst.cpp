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
    priority_queue<int, vector<int>, greater<int>> min_heap;

    int kthSmallest(TreeNode* root, int k) {
        preOrder(root);

        for (int i = 0; i < k-1; i++) {
            min_heap.pop();
        }
        return min_heap.top();
    }

    void preOrder(TreeNode* node) {
        if (!node) {
            return;
        }

        min_heap.push(node->val);
        preOrder(node->left);
        preOrder(node->right);
    }
};