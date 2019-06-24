#include "solution.h"

#include <vector>

using namespace std;


vector<char> String2CharVector(string s) {
    vector<char> res;
    for (int i = 0; i < s.size(); ++i) {
        res.push_back(s[i]);
    }
    return res;
}

string CharVector2String(vector<char> charVector) {
    string res;
    for (int i = 0; i < charVector.size(); ++i) {
        res = res + charVector[i];
    }
    return res;
}

void assertReverseString(string str1, string res) {
    Solution s;
    vector<char> charVector = String2CharVector(str1);
    s.reverseString(charVector);
    string resStr = CharVector2String(charVector);
    assert(res == resStr);
}

int main() {
    assertReverseString("hello", "olleh");
    return 0;
}

