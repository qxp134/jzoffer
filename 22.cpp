#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<char> matching_sta;
    std::string cache_str;
    formed_vec_.clear();
    dfs(n, matching_sta, cache_str);
    return formed_vec_;
  }
  void dfs(int n, std::vector<char> matching_sta, std::string cache_str) {
    if (n == 0) {
      while (!matching_sta.empty()) {
        matching_sta.pop_back();
        cache_str.push_back(')');
      }
      formed_vec_.push_back(cache_str);
      return;
    }
    if (!matching_sta.empty()) {
      matching_sta.pop_back();
      cache_str.push_back(')');
      dfs(n, matching_sta, cache_str);
      matching_sta.push_back('(');
      cache_str.pop_back();
    }
    matching_sta.push_back('(');
    cache_str.push_back('(');
    dfs(n - 1, matching_sta, cache_str);
    return;
  }

 private:
  std::vector<std::string> formed_vec_;
};
