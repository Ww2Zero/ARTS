struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *fast = dummy;
        ListNode *slow = dummy;
        int pos = n + 1;
        while (pos > 0 && fast != nullptr) {
            fast = fast->next;
            pos--;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;

        slow = dummy->next;
        delete dummy;
        return slow;
    }
};