struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *ptr = dummy;

        while (ptr->next) {
            ListNode *start = ptr->next;
            ListNode *end = ptr;
            int i = k;
            while (i > 0) {
                if (end->next) {
                    end = end->next;
                } else {
                    ptr = dummy->next;
                    delete dummy;
                    return ptr;
                }
                i--;
            }
            /**
             *  k=2
             *  d->1->2->3->4->5
             *  |  |  |  |
             *  p  s  e  c
             *
             *
             *  d->2->1->3->4->5
             *  |  |  |  |
             *  p  e  s  c
             *
             *  --------------------------------
             *  k=3
             *  d->1->2->3->4->5
             *  |  |     |  |
             *  p  s     e  c
             *
             *  d->3->2->1->4->5
             *  |  |     |  |
             *  p  e     s  c
             *
             *
             */
            ListNode *cur = end->next;
            ptr->next = reverse(start, cur);
            start->next = cur;
            ptr = start;
            end = start;
        }
        ptr = dummy->next;
        delete dummy;
        return ptr;
    }

    ListNode *reverse(ListNode *node, ListNode *stopNode) {
        ListNode *dummy = new ListNode(-1);
        while (node && node != stopNode) {
            ListNode *next = node->next;
            node->next = dummy->next;
            dummy->next = node;
            node = next;
        }
        return dummy->next;
    }

    ListNode *reverse(ListNode *node) {
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