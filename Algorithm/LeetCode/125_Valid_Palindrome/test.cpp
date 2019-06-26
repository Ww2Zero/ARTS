#include "solution.h"


using namespace std;


void assertIsPalindrome(string str1,bool res) {
    Solution s;

    bool resStr = s.isPalindrome(str1);
    assert(res == resStr);
}

int main() {
    assertIsPalindrome("race a car", false);
    return 0;
}

