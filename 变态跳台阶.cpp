class Solution {
public:
    int jumpFloorII(int number) {
        int num = 1;
        for(int i = 1;i < number;i++)
            num *= 2;
        return num;
    }
};
