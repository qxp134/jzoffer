#include <climits>
#include <cmath>
#include <iostream>
class Solution {
 public:
  int divide(int dividend, int divisor) {
    bool is_negative = false;
    is_negative = std::signbit(dividend) != std::signbit(divisor);
    long long quotient = 0;       // NOLINT
    long long positive_dividend;  // NOLINT
    positive_dividend = std::abs(
        dividend);  // if dividend equel with INT_MIN abs(dividend) out of range
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
      quotient = -quotient;
    if (quotient > INT_MAX || quotient < INT_MIN)
      quotient = INT_MAX;
    return quotient;
  }
};
