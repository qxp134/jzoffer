class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())return false;
        int hang = array.size();
        int row = array[0].size();
        int i = 0;
        int j = row - 1;
        while(i < hang && j > -1){
            if(target == array[i][j])return true;
            else if(target > array[i][j]&&i + 1< hang)i++;
            else if(target < array[i][j]&&j > 0)j--;
            else return false;
        }
        return false;
    }
    
};
