struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr||head->next ==nullptr)   {
            return head;
        }

        ListNode * odd = head;
        ListNode * even = head->next;
        ListNode * evenHead = even;
        while(even !=nullptr && even->next!=nullptr){
            odd->next =odd->next->next;
            odd = odd->next;
            even->next=even->next->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
    }
};