// https://leetcode-cn.com/problems/3sum-closest/
#include <limits.h>

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
 public:
  int threeSumClosest(std::vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int last_num = 999;

    int len = nums.size();
    int ans = nums[0] + nums[len - 1] + nums[len - 2];
    int min_diff = abs(target - ans);
    for (int i = 0; i < len; ++i) {
      if (nums[i] == last_num) {
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
          ans = target + diff;
          min_diff = abs(diff);  // frist commit I forget abs
        }
      }
    }
    return ans;
  }
};