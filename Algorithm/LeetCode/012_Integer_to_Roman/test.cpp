#include "solution.h"

using namespace std;


void assertIntToRoman(int num,string str) {
    Solution s;
    string resStr =s.intToRoman(num);
    assert(resStr == str);
}

int main() {
    assertIntToRoman(4,"IV");
    assertIntToRoman(3,"III");
    return 0;
}