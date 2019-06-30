
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            while (left < right && !isVowel(s[left])) {
                ++left;
            }
            while (left < right && !isVowel(s[right])) {
                --right;
            }
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            ++left;
            --right;
        }
        return s;
    }

    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            return true;
        }
        return false;
    }
};