#include <string>
#include <math.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int chars[256] = {0};
        int left = 0;
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            int charNum = s[i];
            left = max(left, chars[charNum]);
            chars[charNum] = i;
            res = max(res, i - left);
        }
        return res;
    }
};