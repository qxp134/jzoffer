class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int minp = INT_MAX;
        for(auto i = rotateArray.begin();i != rotateArray.end();i++){
            if(*i < minp)minp = *i;
        }
        if(minp == INT_MAX)return 0;
        return minp;
    }
};
