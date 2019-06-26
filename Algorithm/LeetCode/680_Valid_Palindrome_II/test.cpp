#include "solution.h"


using namespace std;


void assertValidPalindrome(string str1, bool res) {
    Solution s;
    bool resStr = s.validPalindrome(str1);
    assert(res == resStr);
}

int main() {
    assertValidPalindrome("aba", false);
    return 0;
}

