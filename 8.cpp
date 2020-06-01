//https://leetcode-cn.com/problems/string-to-integer-atoi/submissions/
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {//第一遍失败了，最后结果可能long long都放不下
		int positive_num = 0;
		long long res = 0;
		auto i = str.begin();
		for (; i != str.end(); i++)//开头空白去掉
		{
			if (*i == ' ')
			{
				continue;
			}
			else
			{
				if (*i == '+'){
					positive_num = 1;
					i++;
				}
				else if(*i == '-'){
					positive_num = 2;
					i++;
				}
				else if (*i < '0' || *i > '9')
					return 0;
				break;
			}
		}
		if (i == str.end())
		{
			return 0;
		}
		string res_str(i, str.end());
		for (i = res_str.begin(); i != res_str.end(); i++)
		{
			if (*i < '0' || *i > '9')
			{
				break;
			}
			res = res * 10 + (*i - '0');
			if (res > INT_MAX)
				break;
		}
		if (positive_num == 2)
		{
			res = -res;
			if (res < INT_MIN)
			{
				return INT_MIN;
			}
		}
		else
		{
			if (res > INT_MAX)
			{
				return INT_MAX;
			}
		}
		return res;	
	}

};

int main()
{
	string test_str("-2000000000000000000");
	Solution s;
	cout << s.myAtoi(test_str);
	return 0;
}