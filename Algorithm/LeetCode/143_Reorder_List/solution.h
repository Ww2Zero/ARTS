struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return;
        }
        ListNode *midNode = getMidNode(head);
        ListNode *newHead = reverseList(midNode->next);
        midNode->next = nullptr;

        ListNode *oldHead = head;
        while (oldHead && newHead) {
            ListNode *oldNext = oldHead->next;
            ListNode *newNext = newHead->next;
            oldHead->next = newHead;
            newHead->next = oldNext;
            oldHead = oldNext;
            newHead = newNext;
        }
    };

    ListNode *getMidNode(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    };

    ListNode *reverseList(ListNode *head) {
        ListNode *tmp = new ListNode(-1);
        while (head) {
            ListNode *t = head->next;
            head->next = tmp->next;
            tmp->next = head;
            head = t;
        }
        return tmp->next;
    };
};