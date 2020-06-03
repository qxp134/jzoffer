#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int maxArea(vector<int>& height) {
		long max = 0;
		long left_max_ = 0;
		for (int i = 0; i < height.size(); i++)
		{
			if (height[i] <= left_max_)
			{
				continue;
			}
			else
			{
				left_max_ = height[i];
			}
			for (int j = height.size() - 1; j > i; j--)
			{
				long high = height[i] < height[j] ? height[i] : height[j];
				long area = (j - i) * high;
				if (max < area)
				{
					max = area;
				}
				if (height[j] >= height[i])
					break;
			}
		}
		return max;
	}
};
//两个for嵌套果然超时了，后来想了排序，存map等均不行，考虑到对面积有影响的因素是距离和最短的那块板，从后往前比不就行了，如果找到比自己长的板，直接break；
//通过上面的剪枝，快了一点点，但是复杂度还是n2   1992ms

//想到了，还可以继续剪枝，从左向右的时候遇到比之前最大值要小的，可以跳过 16ms

//看了题解，使用双指针，短的往里移动，面积可能会变大，长的往里移动面积一定会变小