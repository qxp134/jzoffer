#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> generateParenthesis(int n) {
    int depth = 0;
    std::string cache_str;
    formed_vec_.clear();
    dfs(n, depth, cache_str);
    return formed_vec_;
  }
  void dfs(int n, int depth, std::string cache_str) {
    if (n == 0) {
      while (depth != 0) {
        --depth;
        cache_str.push_back(')');
      }
      formed_vec_.push_back(cache_str);
      return;
    }
    if (depth != 0) {
      --depth;
      cache_str.push_back(')');
      dfs(n, depth, cache_str);
      ++depth;
      cache_str.pop_back();
    }
    ++depth;
    cache_str.push_back('(');
    dfs(n - 1, depth, cache_str);
    return;
  }

 private:
  std::vector<std::string> formed_vec_;
};
