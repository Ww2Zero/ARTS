#include "solution.h"

using namespace std;


void assertRestoreIpAddresses(string target,vector<string> exp) {
    Solution s;
    vector<string> res =s.restoreIpAddresses(target);
    assert(res == exp);
}

int main() {
    vector<string> res;
    res.push_back("255.255.255.255");
    assertRestoreIpAddresses("255255255255",res);
    return 0;
}