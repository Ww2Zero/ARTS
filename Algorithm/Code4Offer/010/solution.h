// https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
class Solution {
public:
    int fib(int n) {
        int fast = 1;
        int slow = 0;
        if (n == 0) {
            return slow;
        }
        if (n == 1) {
            return fast;
        }
        for (int i = 2; i <= n; i++) {
            fast = fast + slow;
            while (fast > 1e9 + 7) {
                fast = fast - 1e9 - 7;
                slow = slow - 1e9 - 7;
            }
            slow = fast - slow;
        }
        return fast;
    }
};