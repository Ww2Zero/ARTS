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
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        while (pre->next) {
            ListNode *cur = pre->next;
            while (cur->next != nullptr && cur->val == cur->next->val) {
                ListNode *tmp = cur;
                cur = cur->next;
                delete tmp;
            }
            if (cur != pre->next) {
                pre->next = cur->next;
            } else {
                pre = pre->next;
            }
        }
        pre = dummy->next;
        delete dummy;
        return pre;
    }
};