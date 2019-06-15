
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *iter1 = l1;
        ListNode *iter2 = l2;
        ListNode *dummy = new ListNode(-1);
        ListNode *ptr = dummy;
        int carry_num = 0;
        while (iter1 != nullptr || iter2 != nullptr || carry_num) {
            if (iter1) {
                carry_num += iter1->val;
                iter1 = iter1->next;
            }
            if (iter2) {
                carry_num += iter2->val;
                iter2 = iter2->next;
            }
            ptr->next = new ListNode(carry_num % 10);
            carry_num /= 10;
            ptr = ptr->next;

        }
        return dummy->next;
    }
};