/*****************
  LeetCode Reverse Integer

  Reverse digits of an integer.

  Example1: x = 123, return 321
  Example2: x = -123, return -321

  If the integer's last digit is 0, what should the output be?
  ie, cases such as 10, 100.

  Did you notice that the reversed integer might overflow? 
  Assume the input is a 32-bit integer, then the reverse of 1000000003 
  overflows. How should you handle such cases?

  For the purpose of this problem, assume that your function returns 0 
  when the reversed integer overflows.

  time complexity O(logn), space complexity O(1)
*******************/
class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if (x<0) {
            sign = -1;
            x = -x;
        }
        int ret = x%10;
        int mid = x/10;
        while (mid!=0) {
            if (ret <= (INT_MAX - (mid % 10))/10)
                ret = ret*10 + mid%10;
            else
                return 0;
            mid /= 10;
        }
        return ret*sign;
    }
};

