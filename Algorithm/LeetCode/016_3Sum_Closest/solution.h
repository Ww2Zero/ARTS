#include <string>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        int diff = abs(target - closest);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int df = abs(sum - target);
                if (df < diff) {
                    diff = df;
                    closest = sum;
                }
                if (sum < target) {
                    ++left;
                } else if (sum > target) {
                    --right;
                } else {
                    return target;
                }
            }
            while (i < nums.size() - 1 && nums[i + 1] == nums[i]) {
                ++i;
            }
        }
        return closest;
    }
};