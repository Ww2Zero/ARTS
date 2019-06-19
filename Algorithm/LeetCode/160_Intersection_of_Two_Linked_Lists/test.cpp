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

vector<ListNode *> createIntersectionNode(vector<int> l1, int k1, vector<int> l2, int k2) {
    vector<ListNode *> listNodeVector;
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    ListNode *intersectionNode = nullptr;
    for (int i = 0; i < l1.size(); ++i) {
        ptr->next = new ListNode(l1[i]);
        if (i + 1 == k1) {
            intersectionNode = ptr->next;
        }
        ptr = ptr->next;

    }
    listNodeVector.push_back(dummyRoot->next);
    dummyRoot->next = nullptr;
    ptr = dummyRoot;
    for (int j = 0; j < l2.size(); ++j) {
        if (j + 1 == k2) {
            ptr->next = intersectionNode;
            break;
        } else {
            ptr->next = new ListNode(l2[j]);
            ptr = ptr->next;
        }
    }
    listNodeVector.push_back(dummyRoot->next);
    delete dummyRoot;
    return listNodeVector;
}

void assertGetIntersectionNode(vector<int> l1, int k1, vector<int> l2, int k2, vector<int> res) {
    vector<ListNode *> vec = createIntersectionNode(l1, k1, l2, k2);
    Solution s;
    ListNode *resNode = s.getIntersectionNode(vec[0], vec[1]);
    vector<int> intersectionNode = ListNode2Vector(resNode);
    assert(res == (intersectionNode));
}

int main() {
    assertGetIntersectionNode(vector<int>{1, 2, 3, 4, 5}, 3, vector<int>{6, 3, 4, 5}, 2, vector<int>{3, 4, 5});
    return 0;
}