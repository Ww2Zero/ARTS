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

void assertReverseBetween(vector<int> l1, int n1, int n2, vector<int> l2) {
    Solution s;
    ListNode *ListHead1 = vector2ListNode(l1);
    ListNode *resList = s.reverseBetween(ListHead1, n1, n2);
    vector<int> res = ListNode2Vector(resList);
    assert(res == (l2));
}

int main() {
    assertReverseBetween(vector<int>{1, 2, 3, 4, 5}, 2, 4, vector<int>{1, 4, 3, 2, 5});
    return 0;
}