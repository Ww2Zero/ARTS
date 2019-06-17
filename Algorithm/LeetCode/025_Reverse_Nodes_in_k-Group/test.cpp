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

void assertReverseKGroup(vector<int> l1, int nth, vector<int> l2) {
    Solution s;
    ListNode *ListHead1 = vector2ListNode(l1);
    ListNode *resList = s.reverseKGroup(ListHead1, nth);
    vector<int> res = ListNode2Vector(resList);
    assert(res == (l2));
}

void assertReverse(vector<int> l1, int nth, vector<int> l2) {
    Solution s;
    ListNode *ListHead1 = vector2ListNode(l1);
    ListNode *resList = s.reverse(ListHead1);
    vector<int> res = ListNode2Vector(resList);
    assert(res == (l2));
}

int main() {
    assertReverse(vector<int>{1, 2, 3, 4, 5}, 2, vector<int>{5, 4, 3, 2, 1});
    assertReverseKGroup(vector<int>{1, 2, 3, 4, 5}, 2, vector<int>{2, 1, 4, 3, 5});
    return 0;
}