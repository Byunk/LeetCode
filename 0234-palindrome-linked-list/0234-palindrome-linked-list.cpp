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
    bool isPalindrome(ListNode* head) {
        // Calculate Total Size of List
        ListNode* pt = head;
        int size = 1;
        while (pt->next != nullptr) {
            pt = pt->next;
            size++;
        }

        if (size == 1) {
            return true;
        }

        stack<int> s;
        pt = head;

        // Save value until half point
        bool isEven = size % 2 == 0 ? true : false;
        int iter = size / 2;
        while (iter > 0) {
            s.push(pt->val);
            pt = pt->next;
            iter--;
        }

        if (!isEven) {
            pt = pt->next;
        }

        // Compare linked list and vector
        while (pt != nullptr) {
            int n = s.top();
            s.pop();
            if (pt->val != n) {
                return false;
            }
            pt = pt->next;
        }
        return true;
    }
};