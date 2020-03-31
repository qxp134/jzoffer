#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
struct num_pair
{
	int num;
	int group;
};
int main()
{
	stack<char> oper;
	stack<num_pair> num_sta;
	string s;
	int gro = 0;
	string res;
	while(cin >> s)
	{
		if(s == "-1"){
			break;
		}
		if(s[0] == '(')
		{
			gro++;
			oper.push(s[1]);
		}
		else
		{
			int i = 0;
			int temp = 0;
			bool fushu = false;
			for(;i < s.size();i++)
			{
				if(s[i] == ')')
				{
					break;
				}
				if(s[i] == '-')
				{
					fushu = true;
					continue;
				}
				temp = temp * 10 + s[i] - '0';
			}
			if(fushu)
				temp = temp * (-1);
			num_pair temp_pair;
			temp_pair.num = temp;
			temp_pair.group = gro;
			num_sta.push(temp_pair);
			for(;i < s.size();i++)
			{
				vector<int> temp_vec;
				while(!num_sta.empty() && num_sta.top().group == gro)
				{
					temp_vec.push_back(num_sta.top().num);
					num_sta.pop();
				}
				char opera = oper.top();
				oper.pop();
				int res;
				if(opera == 's')
				{
					res = temp_vec[1] - temp_vec[0];
				}
				else if(opera == 'd')
				{
					if(temp_vec[0] == 0){
					     cout << "error";
					     return 0;
					}
					res = temp_vec[1] / temp_vec[0];
				}
				else if(opera == 'a')
				{
					res = 0;
					for(int j = 0;j < temp_vec.size();j++)
					{
						res = res + temp_vec[j];
					}
				}
				else
				{
					res = 1;
					for(int j = 0;j < temp_vec.size();j++)
					{
						cout << temp_vec[j] << endl;
						res = res * temp_vec[j];
					}
				}
				gro--;
				temp_pair.group = gro;
				temp_pair.num = res;
				num_sta.push(temp_pair);
			}
		}
	}
	cout << num_sta.top().num;
	return 0;	
}
