// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
#include <iostream>
#include <string>
#include <vector>
std::vector<std::string> res;
std::vector<std::string> recursion(std::string digits) {
  if (digits.empty()) return res;
  std::string::iterator it = digits.begin();
  int count = 3;
  if (*it != '1') {
    if (*it == '7' || *it == '9') {  // forget num '7'
      count = 4;
    }
    std::vector<std::string> temp_arr[4];
    char start_char;
    if (*it < '8') {
      start_char = (*it - '2') * 3 + 'a';
    } else {
      start_char = (*it - '8') * 3 + 't';
    }

    for (int i = 0; i < count; ++i) {
      temp_arr[i] = res;
      if (temp_arr[i].empty()) {
        std::string temp_str(1, start_char);
        temp_arr[i].push_back(temp_str);
      } else {
        for (auto iter = temp_arr[i].begin(); iter != temp_arr[i].end();
             ++iter) {
          iter->push_back(start_char);
        }
      }
      start_char += 1;
    }
    res.clear();
    for (int i = 0; i < count; ++i) {
      res.insert(res.end(), temp_arr[i].begin(), temp_arr[i].end());
    }
  }
  digits.erase(it);
  return recursion(digits);
}
class Solution {
 public:
  std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> ans = recursion(digits);
    res.clear();
    return ans;
  }
};