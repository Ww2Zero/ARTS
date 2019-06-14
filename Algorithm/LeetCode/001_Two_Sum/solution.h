#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res;
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            int searchNum = target - nums[i];
            if (numMap.find(nums[i]) == numMap.end()) {
                numMap[searchNum] = i;
            } else {
                res.push_back(numMap[nums[i]]);
                res.push_back(i);
            }
        }
        return res;
    }
};

