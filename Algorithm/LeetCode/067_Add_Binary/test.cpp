#include "solution.h"


using namespace std;


void assertAddBinary(string str1,string str2,string res) {
    Solution s;

    string resStr = s.addBinary(str1,str2);
    assert(res == resStr);
}

int main() {
    assertAddBinary("11","1","100");
    return 0;
}

