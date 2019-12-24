class Solution {
public:
    int reverse(int x) {
        vector<int> temp;
        long ans = 0;
        while(x != 0)
        {
            temp.push_back(x % 10);
            x = x / 10;
        }
        for(int i = 0;i < temp.size();i++)
        {
            ans = ans * 10 + temp[i];
            if(ans >= INT_MAX)return 0;
            if(ans <= INT_MIN)return 0;
        }
        return ans;
    }
};
