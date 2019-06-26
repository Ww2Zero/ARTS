
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;
        while (left < right) {

            if (!isAlnum(s[left])) {
                ++left;
            } else if (!isAlnum(s[right])) {
                --right;
            } else if (((s[left] - 'a' + 32) % 32) != ((s[right] - 'a' + 32) % 32)) {
                return false;
            } else {
                ++left;
                --right;
            }
        }
        return true;
    }

    bool isAlnum(char &ch) {
        if (ch >= 'a' && ch <= 'z') {
            return true;
        }
        if (ch >= 'A' && ch <= 'Z') {
            return true;
        }
        if (ch >= '0' && ch <= '9') {
            return true;
        }
        return false;
    }
};