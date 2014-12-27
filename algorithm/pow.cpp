/****************
  LeetCode pow(x, n)

  Implement double pow(double x, int n).

  Discussion:

  Divide and Conquer. Dichotomy
  x^n = x^(n/2) * x^(n/2) * x^(n%2)
  recursively.

  time complexity O(logn), space complexity O(1)
**************/
class Solution {
public:
    double pow(double x, int n) {
        if (x == 0 || x == 1) return x;
        if (n < 0) return 1/power(x, -n);
        return power(x, n);
    }
private:
    double power(double x, int n) {
        if (n == 0) return 1;
        double v = power(x, n/2);
        if (n%2 == 0) return v*v;
        else return v*v*x;
    }
};
