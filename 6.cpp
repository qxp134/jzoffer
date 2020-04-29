#include <iostream> 
#include <string> 
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		int flag = 1;
		long long temp;
		if (x < 0)
		{
			flag = -1;
			temp = -x;
		}
		else
		{
			temp = x;
		}
		long long ans = 0;
		while (temp != 0)
		{
			ans = ans * 10 + temp % 10;
			temp = temp / 10;
		}
		ans = ans * flag;
		if (ans > ((1 << 31)) - 1 || ans < -(1 << 31))return 0;
		return (int)ans;
	}
};
int main()
{
	Solution a;
	cout << a.reverse(-213648);
}