class Solution {
public:
    int Fibonacci(int n) {
        int a[2] = {0,1};
        if(n < 2)return a[n];
        int ans;
        for(int i = 2;i <= n;i++){
            ans = a[0] + a[1];
            a[0] = a[1];
            a[1] = ans;
        }
        return ans;
    }
};
