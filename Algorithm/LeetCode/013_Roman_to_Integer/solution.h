#include <string>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (i == len - 1) {
                res += transChar(s[i]);
                break;
            }
            if (transChar(s[i]) < transChar(s[i + 1])) {
                res -= transChar(s[i]);
            } else {
                res += transChar(s[i]);
            }
        }
        return res;
    }

    int transChar(char ch) {
        switch (ch) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }
};