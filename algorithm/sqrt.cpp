/***************
  LeetCode sqrt(x)

  Implement int sqrt(int x).

  Compute and return the square root of x.

  Discussion:

  Divide and Conquer. uses binary search. 
  since the return type is integer, the return value should be smaller or equal
  than the real sqrt(x).

  time complexity O(logn), space complexity O(1)
****************/
class Solution {
public:
    int sqrt(int x) {
        int start = 1;
        int end = x/2;
        int ret;
        if (x < 2) return x;
        while (start <= end) {
            int mid = start + (end - start)/2;
            if (x/mid > mid) {  // mid * mid will cause overflow
                start = mid + 1;
                ret = mid;
            }
            else if (x/mid < mid)
                end = mid - 1;
            else
                return mid;
        }
        return ret;
    }
};
