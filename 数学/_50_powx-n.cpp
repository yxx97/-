//二分查找
class Solution1 {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n ==-1) return 1/x;
        bool neg = n&1;
        double half = myPow(x,n>>1);
        half *= half;
        return (neg)?(half*x):half;

    }
};

// 快速幂 
class Solution2 {
public:
    double myPow(double x, int n) {
        long y = (n<0)?-(long)n : n; 
        double res = 1;
        while (y>0){
            if((y&1)==1){
                res *= x;
            
            }
            x*= x;
            y>>=1;
        }
        return (n>0) ? res : 1/res;
    }
};