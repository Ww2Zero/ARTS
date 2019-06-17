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

void assertRemoveNthFromEnd(vector<int> l1, int nth, vector<int> l2) {
    Solution s;
    ListNode *ListHead1 = vector2ListNode(l1);
    ListNode *resList = s.removeNthFromEnd(ListHead1, nth);
    vector<int> res = ListNode2Vector(resList);
    assert(res == (l2));
}

int main() {
    assertRemoveNthFromEnd(vector<int>{1, 1, 2, 3}, 1, vector<int>{1, 1, 2});
    assertRemoveNthFromEnd(vector<int>{1, 2, 3, 3}, 7, vector<int>{2, 3, 3});
    assertRemoveNthFromEnd(vector<int>{1, 2, 3, 3}, 3, vector<int>{1, 3, 3});
    return 0;
}