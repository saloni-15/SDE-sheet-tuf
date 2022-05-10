/*
Link : https://leetcode.com/problems/powx-n/

Optimal Approach : (Using Binary Exponentiation)
T.C : O(logn)
*/
double powxn(double x, int n){
    if(n==0) return 1;
    double ans = powxn(x, n/2);
    if(n&1) return x*ans*ans;
    else return ans*ans;
}
double myPow(double x, int n) {
    double ans = powxn(x, n);
    return (n>0) ? ans : double(1.0/ans);
}


/*
1. Linearly multiply x n times using for loop
T.C : O(n)
S.C : O(1)
*/
double myPow(double x, int n) {
    double ans = 1.0;
    for(double i=1; i<=abs(n); i++){
        ans *= x;
    }
    return ((n>0) ? ans : double(1.0/ans));
}