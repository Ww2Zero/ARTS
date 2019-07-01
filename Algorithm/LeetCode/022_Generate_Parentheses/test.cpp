#include "solution.h"

using namespace std;


void assertGenerateParenthesis(int n,vector<string> exp) {
    Solution s;
    vector<string> res =s.generateParenthesis(n);
    assert(exp == res);
}

int main() {
    assertGenerateParenthesis(3,{"((()))","(()())","(())()","()(())","()()()"});
    return 0;
}