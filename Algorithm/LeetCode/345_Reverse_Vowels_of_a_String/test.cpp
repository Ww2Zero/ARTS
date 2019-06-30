#include "solution.h"

#include <vector>

using namespace std;


void assertRverseVowels(string str1, string exp) {
    Solution s;
    string res = s.reverseVowels(str1);
    assert(res == exp);
}

int main() {
    assertRverseVowels("hello", "holle");
    return 0;
}

