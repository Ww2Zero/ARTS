#include <string>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(n, n, "", res);
        return res;

    }

    void backtrack(int left, int right, string out, vector<string> &res) {
        if (left == 0 && right == 0) {
            res.push_back(out);
        }
        if (left > right) {
            return;
        }
        if (left > 0) {
            backtrack(left - 1, right, out + '(', res);
        }
        if (right > 0) {
            backtrack(left, right - 1, out + ')', res);
        }
    }
};