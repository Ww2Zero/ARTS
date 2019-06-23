#include <string>
#include <math.h>
#include <stack>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (i != 0 && s[i - 1] == ' ') {
                    res = 1;
                } else {
                    ++res;
                }
            }
        }
        return res;
    }
};