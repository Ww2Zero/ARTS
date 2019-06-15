struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *ptr = head;
        while (ptr->next) {
            if (ptr->val == ptr->next->val) {
                ListNode *tmp = ptr->next;
                ptr->next = tmp->next;
                delete tmp;
            } else {
                ptr = ptr->next;
            }
        }
        return head;
    }
};