// https://leetcode-cn.com/problems/3sum-closest/
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
 public:
  int threeSumClosest(const std::vector<int>& input_nums, int target) {
    std::vector<int> nums = input_nums;
    std::sort(nums.begin(), nums.end());
    int last_num = 999;

    int len = nums.size();
    int best_ans = nums[0] + nums[len - 1] + nums[len - 2];
    int min_diff = std::abs(target - best_ans);
    for (int i = 0; i < len; ++i) {
      if (nums[i] == last_num) {
        last_num = nums[i];
        continue;
      }
      int j = i + 1;
      int k = len - 1;
      int rest_target = target - nums[i];
      while (j < k) {
        int diff = nums[j] + nums[k] - rest_target;
        if (diff > 0) {
          --k;
        } else if (diff < 0) {
          ++j;
        } else {
          return target;
        }
        if (abs(diff) < min_diff) {
          best_ans = target + diff;
          min_diff = abs(diff);  // frist commit I forget abs
        }
      }
    }
    return best_ans;
  }
};
