struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        // find mid node
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        //reverse list
        ListNode *last = slow->next;
        ListNode *pre = head;
        while (last && last->next) {
            ListNode *tmp = last->next;
            last->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        // compare list node
        while (slow->next) {
            slow = slow->next;
            if (pre->val != slow->val) {
                return false;
            }
            pre = pre->next;
        }
        return true;
    }
};