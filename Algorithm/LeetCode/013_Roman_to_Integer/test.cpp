#include "solution.h"

using namespace std;


void assertRomanToInt(string str,int num) {
    Solution s;
    int resNum =s.romanToInt(str);
    assert(resNum == num);
}

int main() {
    assertRomanToInt("IV",4);
    assertRomanToInt("III",3);
    return 0;
}