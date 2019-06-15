#include "solution.h"

#include <vector>

using namespace std;

ListNode *vector2ListNode(vector<int> list) {
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

int main() {

    Solution s;
    vector<ListNode *> NodeListVector;

    ListNode *ListHead1 = vector2ListNode(vector<int>{1, 3, 5});
    ListNode *ListHead2 = vector2ListNode(vector<int>{2, 4});
    ListNode *ListHead3 = vector2ListNode(vector<int>{6, 12});
    ListNode *ListHead4 = vector2ListNode(vector<int>{9, 100});

    NodeListVector.push_back(ListHead1);
    NodeListVector.push_back(ListHead2);
    NodeListVector.push_back(ListHead3);
    NodeListVector.push_back(ListHead4);

    ListNode *resList = s.mergeKLists(NodeListVector);
    vector<int> res = ListNode2Vector(resList);
    assert(res == (vector<int>{1, 2, 3, 4, 5, 6, 9, 12, 100}));
    return 0;
}