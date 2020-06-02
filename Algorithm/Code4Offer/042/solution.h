//https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
#include <vector>

using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max = nums[0];
        int dp = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (dp > 0)
            {
                dp = dp + nums[i];
            }
            else
            {
                dp = nums[i];
            }
            if (dp > max)
            {
                max = dp;
            }
        }
        return max;
    }
};