#include <string>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for (int i = 0; i < digits.size(); ++i) {
            int len = res.size();
            string ss = dict[digits[i] - '2'];
            for (int j = 0; j < len; ++j) {
                string tmp = res.front();
                res.erase(res.begin());
                for (int k = 0; k < ss.size(); ++k) {
                    res.push_back(tmp + ss[k]);
                }
            }

        }
        return res;
    }
};