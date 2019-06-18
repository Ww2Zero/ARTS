#include "solution.h"

#include <vector>

using namespace std;

ListNode *vector2ListNode(vector<int> &list) {
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int i = 0; i < list.size(); ++i) {
        ptr->next = new ListNode(list[i]);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

ListNode *vector2ListNodeCycle(vector<int> &list, int k) {
    vector<ListNode *> ListNodeVector;
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int i = 0; i < list.size(); ++i) {
        ptr->next = new ListNode(list[i]);
        ListNodeVector.push_back(ptr->next);
        ptr = ptr->next;
    }
    // 连接成环
    if (k < list.size()) {
        ptr->next = ListNodeVector[k];
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

vector<int> ListNode2Vector(ListNode *listNode) {
    vector<int> res;
    ListNode *ptr = listNode;
    while (ptr) {
        res.push_back(ptr->val);
        ptr = ptr->next;
    }
    return res;
}

void assertDetectCycle(vector<int> l1, int k, int n) {
    Solution s;
    ListNode *ListHead1 = vector2ListNodeCycle(l1, k);
    ListNode *resNode = s.detectCycle(ListHead1);
    assert(resNode->val == n);
}

int main() {
    assertDetectCycle(vector<int>{1, 2, 3, 4, 5}, 1, 2);
    return 0;
}