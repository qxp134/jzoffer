//https://leetcode-cn.com/problems/3sum/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

struct MyPair
{
	MyPair(int x, int y)
	{
		if (x < y)
		{
			one = x;
			two = y;
		}
		else
		{
			one = y;
			two = x;
		}
	}
	int one;
	int two;
	int index_one;
	int index_two;
	bool operator==(const MyPair target) const
	{
		if (one == target.one && two == target.two)
			return true;

		else
			return false;
	}
	bool operator<(const MyPair target) const
	{
		return one < target.one;
	}
};

class Solution1 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		map<int, set<MyPair>> my_map_;
		vector<vector<int>> res;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				MyPair temp(nums[i], nums[j]);
				temp.index_one = i;
				temp.index_two = j;
				int value = nums[i] + nums[j];
				if (my_map_.find(value) != my_map_.end())
				{
					my_map_[value].insert(temp);
				}
				else
				{
					set<MyPair> set_;
					set_.insert(temp);
					my_map_[value] = set_;
				}
			}
		}
		for (int i = 0; i < nums.size(); i++)
		{
			auto iter = my_map_.find(0 - nums[i]);
			if (iter != my_map_.end())
			{
				for (auto j = iter->second.begin(); j != iter->second.end(); j++)
				{
					if (j->index_one != i && j->index_two != i){
						vector<int> temp;
						temp.push_back(j->one);
						temp.push_back(j->two);
						temp.push_back(nums[i]);
						res.push_back(temp);
					}
				}
				my_map_.erase(iter);
			}
		}
		return res;
	}
};
//������֮����Ϊkey,��������ɵ�Mypair��Ϊvalue ����һ�飬��map�в�ʣ�µ�������
//set��������< �����ظ� ���ڵ��ڵ��ж����� a��С��b b��С��a a�͵���b ��������С�ںŵ�ʱ��Ҫ���� 1
//������������������ظ����������������ظ�
#include <algorithm>
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		//����������Ҫ��
		sort(nums.begin(), nums.end());
		//�����ҵ�˼����һ���������������һ�ߣ���һ������һ�ߣ�Ȼ����١�������һ���������������������ģ���ֻ����ֻ�ȵ��ڣ�Ҳ���Դ��ڣ�С��
		//����ʹ��˫ָ�뷨
		int last_num = 999;
		for (int i = 0; i < nums.size(); i++)
		{
			auto j = i + 1;
			auto k = nums.size() - 1;
			if (nums[i] > 0)break;
			if (last_num == nums[i])
			{
				continue;
			}
			last_num = nums[i];

			while (j < k)
			{
				int ans = nums[i] + nums[j] + nums[k];
				if (ans > 0)
				{
					k--;
				}
				else if (ans < 0)
				{
					j++;
				}
				else
				{
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[j]);
					temp.push_back(nums[k]);
					res.push_back(temp);
					j++;
					while (j < k){
						if (nums[j - 1] == nums[j])
							j++;
						else
							break;
					}
				}
			}
		}
		return res;
	}
};