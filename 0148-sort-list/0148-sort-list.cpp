/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* node = head;
        while (node != nullptr) {
            v.push_back(node->val);
            node = node->next;
        }
        sort(v.begin(), v.end());

        ListNode* dummy = new ListNode();
        node = dummy;
        for (int i = 0; i < v.size(); i++) {
            node->next = new ListNode(v[i]);
            node = node->next;
        }
        return dummy->next;
    }
};