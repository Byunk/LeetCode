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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Set dummy node
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* pt1 = dummy;
        ListNode* pt2 = dummy;

        for (int i = 0; i < n+1; i++) {
            pt2 = pt2->next;
        }

        while (pt2 != nullptr) {
            pt1 = pt1->next;
            pt2 = pt2->next;
        }

        pt1->next = pt1->next->next;
        return dummy->next;
    }
};