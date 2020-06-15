//https://leetcode-cn.com/problems/palindrome-number/
#include <iostream>
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		long long res = 0;
		long long old = x;
		while (x > 0)
		{
			res = res * 10 + x % 10;
			if (res > INT_MAX)
				return false;
			x /= 10;
		}
		if (old == res)
		{
			return true;
		}
		return false;
	}
};