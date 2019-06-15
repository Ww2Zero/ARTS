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

void assertAddTwoNumbers(vector<int> l1, vector<int> l2, vector<int> l3) {
    Solution s;
    ListNode *ListHead1 = vector2ListNode(l1);
    ListNode *ListHead2 = vector2ListNode(l2);
    ListNode *resList = s.addTwoNumbers(ListHead1, ListHead2);
    vector<int> res = ListNode2Vector(resList);
    assert(res == (l3));
}

int main() {
    assertAddTwoNumbers(vector<int>{2, 4, 3}, vector<int>{5, 6, 4}, vector<int>{7, 0, 8});
    assertAddTwoNumbers(vector<int>{2, 4, 3}, vector<int>{5, 6, 6}, vector<int>{7, 0, 0, 1});
    return 0;
}