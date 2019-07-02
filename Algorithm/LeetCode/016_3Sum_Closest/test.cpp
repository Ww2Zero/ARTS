#include "solution.h"

using namespace std;


void assertThreeSumClosest(vector<int> vec, int target, int exp) {
    Solution s;
    int res = s.threeSumClosest(vec, target);
    assert(res == exp);
}

int main() {

    assertThreeSumClosest({-1, 2, 1, -4}, 1, 2);
    return 0;
}