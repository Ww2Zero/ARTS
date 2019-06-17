struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {

        if (head == nullptr) {
            return nullptr;
        }
        if (k < 0) {
            return nullptr;
        }
        ListNode *cur = head;
        int len = 1;
        while (cur->next) {
            ++len;
            cur = cur->next;
        }
        // 计算距离头节点的位置
        int m = len - k % len;
        // 连接成环
        cur->next = head;
        for (int i = 0; i < m; ++i) {
            cur = cur->next;
        }
        // 保存新的头节点
        ListNode *newHead = cur->next;
        // 斩断环
        cur->next = nullptr;
        return newHead;
    }
};