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
    ListNode* middleNode(ListNode* head) {
        ListNode* pt = head;
        int size = 0;
        while (pt != nullptr) {
            size++;
            pt = pt->next;
        }

        int idx = size / 2 + 1;
        pt = head;
        for (int i = 1; i < idx; i++) {
            pt = pt->next;
        }
        return pt;
    }
};