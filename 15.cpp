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
//将两数之和作为key,两个数组成的Mypair作为value 遍历一遍，从map中查剩下的两个数
//set可以重载< 避免重复 对于等于的判定方法 a不小于b b不小于a a就等于b 所以重载小于号的时候要讲究 1
//这个方法放弃，会有重复，并且难以消除重复
#include <algorithm>
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		//首先排序是要的
		sort(nums.begin(), nums.end());
		//这里我的思想是一定有两个数在零的一边，另一个在另一边，然后穷举。忽略了一个条件，这个数组是有序的，不只可以只比等于，也可以大于，小于
		//可以使用双指针法
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