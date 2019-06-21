#include "solution.h"

using namespace std;


void assertLongestCommonPrefix(vector<string> strVector, string targetStr) {
    Solution s;
    string resStr = s.longestCommonPrefix(strVector);
    assert(resStr == targetStr);
}

int main() {
    assertLongestCommonPrefix(vector<string>{"flow", "flee", "flww"}, "fl");
    assertLongestCommonPrefix(vector<string>{"ff", "ee", "rr"}, "");
    return 0;
}