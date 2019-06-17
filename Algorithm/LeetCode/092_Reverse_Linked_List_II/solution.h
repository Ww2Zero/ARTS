struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == nullptr) {
            return nullptr;
        }
        if (n < m || n < 0 || m < 0) {
            return nullptr;
        }
        if (n - m < 1) {
            return head;
        }

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *ptr = dummy;
        ListNode *start = nullptr;
        ListNode *end = nullptr;
        ListNode *next = nullptr;

        while (m > 1 && ptr != nullptr) {
            end = ptr->next;
            ptr = ptr->next;
            n--;
            m--;
        }

        while (n > 0 && end != nullptr) {
            end = end->next;
            n--;
        }
        /**
         *
         * m=2 n=4
         * -1->1->2->3->4->5->6
         *  |  |  |     |  |
         *  d  p  s     e  n
         *
         *  ------------------------
         * -1->1->>4->3->2->>5->6
         *  |  |   |     |   |
         *  d  p   e     s   n
         *
         */
        next = end->next;
        start = ptr->next;
        ptr->next = reverse(start, next);
        start->next = next;
        return dummy->next;

    }

    ListNode *reverse(ListNode *startNode, ListNode *stopNode) {
        ListNode *dummy = new ListNode(-1);
        while (startNode && startNode != stopNode) {
            ListNode *next = startNode->next;
            startNode->next = dummy->next;
            dummy->next = startNode;
            startNode = next;
        }
        return dummy->next;
    }
};