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

void assertIsPalindrome(vector<int> l1, bool isPalindrome) {
    Solution s;
    ListNode *ListHead1 = vector2ListNode(l1);
    bool res = s.isPalindrome(ListHead1);

    assert(res == (isPalindrome));
}

int main() {
    assertIsPalindrome(vector<int>{1, 2, 3, 4, 5}, false);
    assertIsPalindrome(vector<int>{1, 2, 2, 1}, true);
    assertIsPalindrome(vector<int>{1, 2, 2, 1, 1}, false);
    return 0;
}