struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *ptr = dummy;
        while (ptr->next) {
            if (ptr->next->val == val) {
                ListNode *t = ptr->next;
                ptr->next = t->next;
                delete t;
            } else {
                ptr = ptr->next;
            }
        }
        ptr = dummy->next;
        delete dummy;
        return ptr;
    }
};