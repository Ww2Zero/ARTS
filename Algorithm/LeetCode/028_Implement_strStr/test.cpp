#include "solution.h"

using namespace std;


void assertStrStr(string str1,string str2 ,int num) {
    Solution s;
    int resNum =s.strStr(str1,str2);
    assert(resNum == num);
}

int main() {
    assertStrStr("hello","ll",2);
    return 0;
}