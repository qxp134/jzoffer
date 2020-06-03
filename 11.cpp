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
//����forǶ�׹�Ȼ��ʱ�ˣ������������򣬴�map�Ⱦ����У����ǵ��������Ӱ��������Ǿ������̵��ǿ�壬�Ӻ���ǰ�Ȳ������ˣ�����ҵ����Լ����İ壬ֱ��break��
//ͨ������ļ�֦������һ��㣬���Ǹ��ӶȻ���n2   1992ms

//�뵽�ˣ������Լ�����֦���������ҵ�ʱ��������֮ǰ���ֵҪС�ģ��������� 16ms

//������⣬ʹ��˫ָ�룬�̵������ƶ���������ܻ��󣬳��������ƶ����һ�����С