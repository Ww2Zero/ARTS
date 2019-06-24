
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.size() - 1;
        int n = b.size() - 1;
        int carry = 0;
        while (m >= 0 || n >= 0) {
            int q = m >= 0 ? a[m--] - '0' : 0;
            int p = n >= 0 ? b[n--] - '0' : 0;
            int sum = q + p + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        return carry == 1 ? "1" + res : res;

    }
};