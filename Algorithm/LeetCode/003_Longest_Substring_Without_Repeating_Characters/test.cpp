#include "solution.h"

using namespace std;


void assertLengthOfLongestSubstring(string  str,int len) {
    Solution s;
    int l =s.lengthOfLongestSubstring(str);
    assert(l == len);
}

int main() {
    assertLengthOfLongestSubstring("abcabc",3);
    assertLengthOfLongestSubstring("pwwkew",3);
    return 0;
}