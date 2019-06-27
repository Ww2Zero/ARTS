#include "solution.h"

using namespace std;


void assertThreeSum(vector<int> &vec, vector<vector<int>> &exp) {
    Solution s;
    vector<vector<int>> res = s.threeSum(vec);
    assert(res == exp);
}

int main() {
    vector<int> v = {-2, 0, 1, 1, 2};
    vector<vector<int>> r;
    r.push_back({-2, 0, 2});
    r.push_back({-2, 1, 1});

    assertThreeSum(v, r);
    return 0;
}