#include "solution.h"

#include <vector>
#include <assert.h>

using namespace std;

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> numVector1 = {-3, 6, 11, 5, 15, -14, 39};

    assert((s.twoSum(numVector1, 3) == vector<int>{0, 1}));
    assert((s.twoSum(numVector1, 17) == vector<int>{1, 2}));
    assert((s.twoSum(numVector1, 25) == vector<int>{5, 6}));

    vector<int> numVector2 = {2, 7, 11, 5};
    assert((s.twoSum(numVector2, 9) == vector<int>{0, 1}));
    assert((s.twoSum(numVector2, 13) == vector<int>{0, 2}));
    return 0;
}
