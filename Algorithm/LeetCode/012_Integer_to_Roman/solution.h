#include <string>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> vals = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> strs = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string res = "";
        for (int i = 0; i < vals.size(); ++i) {
            while (num >= vals[i]) {
                res += strs[i];
                num -= vals[i];
            }
        }
        return res;
    }
};