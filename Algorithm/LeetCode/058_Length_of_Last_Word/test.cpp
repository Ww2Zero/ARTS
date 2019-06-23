#include "solution.h"

using namespace std;


void assertLengthOfLastWord(string str1,int num) {
    Solution s;
    int resNum =s.lengthOfLastWord(str1);
    assert(resNum == num);
}

int main() {
    assertLengthOfLastWord("hello ll",2);
    return 0;
}