struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *longList = headA;
        ListNode *shortList = headB;
        int alen = getListLen(longList);
        int blen = getListLen(shortList);

        int diff = 0;
        if (alen > blen) {
            longList = headA;
            shortList = headB;
            diff = alen - blen;
        } else {
            longList = headB;
            shortList = headA;
            diff = blen - alen;
        }

        while (diff) {
            longList = longList->next;
            --diff;
        }
        while (longList && shortList) {
            if (longList == shortList) {
                return longList;
            }
            longList = longList->next;
            shortList = shortList->next;
        }
        return nullptr;


    }

    int getListLen(ListNode *head) {
        int len = 0;
        while (head) {
            head = head->next;
            ++len;
        }
        return len;
    }
};