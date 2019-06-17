struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {

        if (head == nullptr) {
            return nullptr;
        }

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *ptr = dummy;
        while (ptr->next && ptr->next->next) {
            ListNode *t1 = ptr->next;
            ListNode *t2 = ptr->next->next;
            // t1 t2 交换位置
            t1->next = t2->next;
            ptr->next = t2;
            t2->next = t1;
            // 向后移动ptr
            ptr = t1;
        }
        ptr = dummy->next;
        delete dummy;
        return ptr;
    }
};