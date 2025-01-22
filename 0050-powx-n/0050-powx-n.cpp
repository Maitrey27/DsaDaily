class Solution {
public:
 double myPow(double x, int n) {
        if(n==0) return 1;

        long long exp = n;
        if(exp<0) {
            exp = -(exp);
            x = 1/x;
        }
        if(exp%2==0){
            return myPow(x*x, exp/2);
        }
        else{
            return x*myPow(x, exp-1);
        }
    }
};