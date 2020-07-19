/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
*/
class Solution {
public:
    double myPow(double x, int n) {
     
        if(n==0)
             return 1;
        double t=myPow(x,n/2);
        
        if(n%2)
            return n<0? 1/x*t*t:x*t*t; 
        else
            return t*t;
    }
};
