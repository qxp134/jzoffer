https
    :  // leetcode-cn.com/problems/integer-to-roman/submissions///https://leetcode-cn.com/problems/integer-to-roman/
       class Solution {
 public:
  string intToRoman(int num) {
    string res;
    string one = "IXCM";
    string five = "VLD";
    int index = 0;
    while (num != 0) {
      int signal = num % 10;
      if (signal < 4) {
        for (int i = 0; i < signal; i++) {
          res.push_back(one[index]);
        }
      } else if (signal == 4) {
        res.push_back(five[index]);
        res.push_back(one[index]);
      } else if (signal != 9) {
        for (int i = 5; i < signal; i++) {
          res.push_back(one[index]);
        }
        res.push_back(five[index]);
      } else {
        res.push_back(one[index + 1]);
        res.push_back(one[index]);
      }
      index++;
      num = num / 10;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
