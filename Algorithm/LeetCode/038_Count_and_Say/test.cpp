#include "solution.h"

using namespace std;


void assertCountAndSay(int n,string exp) {
    Solution s;
    string res =s.countAndSay(n);
    assert(res == exp);
}

int main() {
    assertCountAndSay(1,"1");
    assertCountAndSay(2,"11");
    assertCountAndSay(3,"21");
    assertCountAndSay(4,"1211");
    assertCountAndSay(5,"111221");
    return 0;
}