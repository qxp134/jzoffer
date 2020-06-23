// https://leetcode-cn.com/problems/4sum
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int> > fourSum(
      std::vector<int>& nums, int target) {
    std::vector<std::vector<int> > four_sum_vec;
    std::sort(nums.begin(), nums.end());
    int last_frist_num = 999;
    int len = nums.size();
    std::vector<int> base_vec;
    for (int i = 0; i < len; ++i) {
      if (nums[i] == last_frist_num) {
        continue;
      }
      last_frist_num = nums[i];
      int last_sec_num = 999;
      for (int j = i + 1; j < len; ++j) {
        if (nums[j] == last_sec_num) {
          continue;
        }
        last_sec_num = nums[j];
        int k = j + 1;
        int l = len - 1;
        int rest_target = target - nums[i] - nums[j];
        while (k < l) {
          int diff = nums[k] + nums[l] - rest_target;
          if (diff > 0) {
            --l;
          } else if (diff < 0) {
            ++k;
          } else {
            four_sum_vec.emplace_back(std::vector<int>({nums[i], nums[j], nums[k], nums[l]}));
            base_vec.clear();
            ++k;
            while (k < l) {
              if (nums[k - 1] == nums[k])
                k++;
              else
                break;
            }
          }
        }
      }
    }
    return four_sum_vec;
  }
};