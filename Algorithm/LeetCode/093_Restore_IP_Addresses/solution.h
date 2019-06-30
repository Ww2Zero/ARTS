#include <string>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        for (int a = 0; a < 4; ++a) {
            for (int b = 0; b < 4; ++b) {
                for (int c = 0; c < 4; ++c) {
                    for (int d = 0; d < 4; ++d) {
                        if (a + b + c + d == s.size()) {
                            int anum = stoi(s.substr(0, a));
                            int bnum = stoi(s.substr(a, b));
                            int cnum = stoi(s.substr(a + b, c));
                            int dnum = stoi(s.substr(a + b + c, d));
                            if (anum <= 255 && bnum <= 255 && cnum <= 255 && dnum <= 255) {
                                string t = to_string(anum)
                                           + "." + to_string(bnum)
                                           + "." + to_string(cnum)
                                           + "." + to_string(dnum);
                                if (t.size() == s.size() + 3) {
                                    res.push_back(t);
                                }
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};