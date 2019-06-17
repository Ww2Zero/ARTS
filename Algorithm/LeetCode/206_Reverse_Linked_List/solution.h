struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:

    ListNode *reverseList(ListNode *node) {
        ListNode *dummy = new ListNode(-1);
        while (node) {
            ListNode *next = node->next;
            node->next = dummy->next;
            dummy->next = node;
            node = next;
        }
        return dummy->next;
    }
};