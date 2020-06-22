// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> letterCombinations(std::string digits) {
    return recursion(digits);
  }
  std::vector<std::string> recursion(std::string digits) {
    if (digits.empty())
      return letter_combinations;
    std::string::iterator it = digits.begin();
    if (number_to_chars[*it - '0'] != "") {
      char start_char = number_to_chars[*it - '0'][0];
      int count = number_to_chars[*it - '0'].size();
      std::vector<std::string> temp_arr[4];
      for (int i = 0; i < count; ++i) {
        temp_arr[i] = letter_combinations;
        if (temp_arr[i].empty()) {
          std::string temp_str(1, start_char);
          temp_arr[i].push_back(temp_str);
        } else {
          for (std::string& str : temp_arr[i]) str.push_back(start_char);
        }
        start_char += 1;
      }
      letter_combinations.clear();
      for (int i = 0; i < count; ++i) {
        letter_combinations.insert(letter_combinations.end(), temp_arr[i].begin(), temp_arr[i].end());
      }
    }
    digits.erase(it);
    return recursion(digits);
  }

 private:
  std::vector<std::string> letter_combinations;
  std::string number_to_chars[10] = {"",    "",    "abc",  "def", "ghi",
                                     "jkl", "mno", "pqrs", "tuv", "wxyz"};
};