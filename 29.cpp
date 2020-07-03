#include <climits>
#include <cmath>
#include <iostream>
class Solution {
 public:
  int divide(int dividend, int divisor) {
    bool is_negative = false;
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
      is_negative = true;
    long long quotient = 0;       // NOLINT
    long long positive_dividend;  // NOLINT
    positive_dividend = std::abs(dividend);
    divisor = std::abs(divisor);
    while (positive_dividend >= divisor) {
      long multi_divisor = divisor;  // NOLINT
      long count = 1;                // NOLINT
      while ((multi_divisor << 1) < positive_dividend) {
        multi_divisor = multi_divisor << 1;
        count *= 2;
      }
      positive_dividend -= multi_divisor;
      quotient += count;
    }
    if (is_negative)
      quotient = 0 - quotient;
    if (quotient > INT_MAX || quotient < INT_MIN)
      quotient = INT_MAX;
    return quotient;
  }
};
