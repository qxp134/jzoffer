class Solution {
 public:
  int rectCover(int number) {
    if (number == 1)
      return 1;
    if (number == 0)
      return 0;
    int ans = 2;
    int fri = 1, sec = 2;
    for (int i = 3; i <= number; i++) {
      ans = fri + sec;
      fri = sec;
      sec = ans;
    }
    return ans;
  }
};
