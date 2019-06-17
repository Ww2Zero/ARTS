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

void assertMiddleNode(vector<int> l1, vector<int> l2) {
    Solution s;
    ListNode *ListHead1 = vector2ListNode(l1);
    ListNode *resList = s.middleNode(ListHead1);
    vector<int> res = ListNode2Vector(resList);
    assert(res == (l2));
}

int main() {
    assertMiddleNode(vector<int>{1, 2, 3, 4, 5}, vector<int>{3, 4, 5});
    assertMiddleNode(vector<int>{1, 2, 3, 4, 5, 6}, vector<int>{4, 5, 6});
    return 0;
}