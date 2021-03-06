struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *ptr = dummy;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                ptr->next = l2;
                l2 = l2->next;
            } else {
                ptr->next = l1;
                l1 = l1->next;
            }
            ptr = ptr->next;
        }
        ptr->next = l1 ? l1 : l2;
        return dummy->next;
    }
};