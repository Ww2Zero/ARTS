#include "solution.h"

using namespace std;


void assertIsValid(string str,bool res) {
    Solution s;
    bool resIsValid =s.isValid(str);
    assert(resIsValid == res);
}

int main() {
    assertIsValid("{}",true);
    assertIsValid("{}{",false);
    return 0;
}