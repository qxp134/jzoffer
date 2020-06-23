// https://leetcode-cn.com/problems/4sum
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int> > fourSum(
      const std::vector<int>& nums, int target) {
    std::vector<std::vector<int> > four_sum_vec;
    std::sort(nums.begin(), nums.end());
    int last_fri_num = 999;
    int len = nums.size();
    std::vector<int> base_vec;
    for (int i = 0; i < len; ++i) {
      if (nums[i] == last_fri_num) {
        continue;
      }
      last_fri_num = nums[i];
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
            base_vec.push_back(nums[i]);
            base_vec.push_back(nums[j]);
            base_vec.push_back(nums[k]);
            base_vec.push_back(nums[l]);
            four_sum_vec.push_back(base_vec);
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