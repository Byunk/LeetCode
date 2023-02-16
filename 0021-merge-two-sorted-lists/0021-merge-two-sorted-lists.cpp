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
    ListNode* nextList;
    ListNode* tail;

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        int n = getSize(head);
        ListNode* start = head;
        ListNode* dummy = new ListNode();
        for (int size = 1; size < n; size *= 2) {
            tail = dummy;
            while (start) {
                if (!start->next) {
                    tail->next = start;
                    break;
                }
                ListNode *mid = split(start, size);
                merge(start, mid);
                start = nextList;
            }
            start = dummy->next;
        }
        return dummy->next;
    }

    ListNode* split(ListNode* start, int size) {
        ListNode* midPrev = start;
        ListNode* end = start->next;
        
        // end가 nullptr라더라도 midPrev은 size만큼 이동해야 함.
        // midPrev이 이동할만큼 node가 없을 수 있음.
        for (int i = 1; i < size; i++) {
            if (midPrev->next) {
                midPrev = midPrev->next;
            }

            if (end->next) {
                end = (end->next->next) ? end->next->next : end->next;
            }
        }
        ListNode* mid = midPrev->next;
        nextList = end->next;
        end->next = nullptr;
        midPrev->next = nullptr;
        return mid;
    }

    void merge(ListNode* list1, ListNode* list2) {
        ListNode* pt1 = list1;
        ListNode* pt2 = list2;
        ListNode* dummy = new ListNode();
        ListNode* pt = dummy;
        while(pt1 && pt2) {
            if (pt1->val <= pt2->val) {
                pt->next = pt1;
                pt1 = pt1->next;
            } else {
                pt->next = pt2;
                pt2 = pt2->next;
            }
            pt = pt->next;
        }
        pt->next = (pt1) ? pt1 : pt2;
        while(pt->next) {
            pt = pt->next;
        }
        // Link lists
        tail->next = dummy->next;
        tail = pt;
    }

    int getSize(ListNode* node) {
        int size;
        while (node) {
            size++;
            node = node->next;
        }
        return size;
    }
};
