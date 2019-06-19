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

vector<int> ListNode2Vector(ListNode *listNode) {
    vector<int> res;
    ListNode *ptr = listNode;
    while (ptr) {
        res.push_back(ptr->val);
        ptr = ptr->next;
    }
    return res;
}

void assertReorderList(vector<int> l1, vector<int> l2) {
    Solution s;
    ListNode *ListHead1 = vector2ListNode(l1);
    s.reorderList(ListHead1);
    vector<int> res = ListNode2Vector(ListHead1);
    assert(res == l2);
}

int main() {
    assertReorderList(vector<int>{1, 2, 3, 4}, vector<int>{1, 4, 2, 3});
    assertReorderList(vector<int>{1, 2, 3, 4, 5}, vector<int>{1, 5, 2, 4, 3});
    return 0;
}