#include "solution.h"

using namespace std;


void assertLetterCombinations(string str, vector<string> &exp) {
    Solution s;
    vector<string> res = s.letterCombinations(str);
    assert(res == exp);
}

int main() {
    vector<string> exp = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};

    assertLetterCombinations("23", exp);
    return 0;
}