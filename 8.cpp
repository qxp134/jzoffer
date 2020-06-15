// https://leetcode-cn.com/problems/string-to-integer-atoi/submissions/
#include <iostream>
#include <string>
class Solution {
 public:
  int myAtoi(std::string str) {  //第一遍失败了，最后结果可能long long都放不下
    bool positive_flag = true;
    long long res = 0;
    auto iter = str.begin();
    for (; iter != str.end() && *iter == ' '; ++iter)  //开头空白去掉
    	;
    if (iter == str.end()) return 0;
    if (*iter == '+') ++iter;
    else if (*iter == '-') {
      positive_flag = false;
      ++iter;
    }
    std::string res_str(iter, str.end());
    for (iter = res_str.begin(); iter != res_str.end(); ++iter) {
      if (*iter < '0' || *iter > '9') {
        break;
      }
      res = res * 10 + (*iter - '0');
      if (res > INT_MAX)
        break;
    }
    if (!positive_flag) {
      res = -res;
      if (res < INT_MIN) {
        return INT_MIN;
      }
    } else {
      if (res > INT_MAX) {
        return INT_MAX;
      }
    }
    return res;
  }
};

int main() {
  std::string test_str("-2000000000000000000");
  Solution s;
  std::cout << s.myAtoi(test_str);
  return 0;
}
