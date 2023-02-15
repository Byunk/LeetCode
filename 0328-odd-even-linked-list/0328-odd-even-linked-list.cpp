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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;    
        }

        ListNode* oddNode = new ListNode();
        ListNode* evenNode = new ListNode();;
        ListNode* oddHead = oddNode;
        ListNode* evenHead = evenNode;

        ListNode* node = head->next;

        int idx = 2;
        // traverse O(n)
        while (node != nullptr) {
            if (idx % 2 == 0) {
                evenNode->next = node;
                evenNode = evenNode->next;
            } else {
                oddNode->next = node;
                oddNode = oddNode->next;
            }
            node = node->next;
            idx++;
        }

        // make both end points nullptr
        evenNode->next = nullptr;
        oddNode->next = nullptr;

        // merge
        oddNode = oddHead->next;
        evenNode = evenHead->next;
        node = head;
        while (oddNode != nullptr) {
            node->next = oddNode;
            oddNode = oddNode->next;
            node = node->next;
        }

        while (evenNode != nullptr) {
            node->next = evenNode;
            evenNode = evenNode->next;
            node = node->next;
        }
        return head;
    }
};