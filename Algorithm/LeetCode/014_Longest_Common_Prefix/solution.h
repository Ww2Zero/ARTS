#include <string>
#include <math.h>
#include <vector>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) {
            return "";
        }
        string res = "";
        string firstStr = strs[0];
        for (int i = 0; i < firstStr.size(); ++i) {
            char ch = firstStr[i];

            for (int k = 0; k < strs.size(); ++k) {
                if (i > strs[k].size() || strs[k][i] != ch) {
                    return res;
                }
            }
            res.push_back(ch);
        }
        return res;
    }
};