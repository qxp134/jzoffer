class Solution {
 public:
  int jumpFloor(int number) {
    int n = number;
    int a[2] = {1, 2};
    if (n <= 2)
      return a[n - 1];
    int ans;
    for (int i = 3; i <= n; i++) {
      ans = a[0] + a[1];
      a[0] = a[1];
      a[1] = ans;
    }
    return ans;
  }
};
