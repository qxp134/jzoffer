class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    map<char, int> recode;
    int max_len = 0;
    int temp_len = 0;
    int start_index = 0;
    for (int i = 0; i < s.size(); i++) {
      if (recode.find(s[i]) == recode.end()) {
        temp_len++;
      } else {
        int j = recode[s[i]];
        for (; start_index < j; start_index++) {
          recode.erase(recode.find(s[start_index]));
          temp_len--;
        }
        start_index = j + 1;
      }
      recode[s[i]] = i;
      if (temp_len > max_len)
        max_len = temp_len;
    }
    return max_len;
  }
};
