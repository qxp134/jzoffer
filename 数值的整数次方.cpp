class Solution {
public:
    bool flag = true;
    double Power(double base, int exponent) {
        if(exponent == 1)return base;
        if(exponent == 0)return 1;
        if(exponent < 0){
            flag = false;
            exponent = 0 - exponent;
        }
        double temp = Power(base,exponent/2);
        double res;
        if(exponent%2 == 0){
           res = temp * temp;
        }
        else
            res =  temp * temp * base;
        if(flag)
            return res;
        else
            return 1/res;
    }
};
