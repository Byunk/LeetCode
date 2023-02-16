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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* pt1, * pt2;
        pt1 = list1;
        pt2 = list2;

        ListNode* dummy = new ListNode();
        ListNode* pt = dummy;
        while (pt1 != nullptr && pt2 != nullptr) {
            if (pt1->val <= pt2->val) {
                pt->next = pt1;
                pt1 = pt1->next;
                pt = pt->next;
            } else {
                pt->next = pt2;
                pt2 = pt2->next;
                pt = pt->next;
            }
        }
        while (pt1 != nullptr) {
            pt->next = pt1;
            pt1 = pt1->next;
            pt = pt->next;
        }
        while (pt2 != nullptr) {
            pt->next = pt2;
            pt2 = pt2->next;
            pt = pt->next;
        }
        return dummy->next;
    }
};
