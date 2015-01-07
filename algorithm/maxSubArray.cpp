/****************
  LeetCode Maximum Subarray

  Find the contiguous subarray within an array (containing at least one number)
  which has the largest sum.

  For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
  the contiguous subarray [4,−1,2,1] has the largest sum = 6.

  Discussion:
  Dynamic Programming.
  
  For an element of tha array, there are only two options to contribute to the 
  maximum subarray. 1. join to the previous subSum to make it larger; 
  2. start a new subarray if the previous subSum is <= 0.

  time complexity O(n), space complexity O(1)
****************/
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int result = INT_MIN;
        int subSum = 0;
        for (int i=0; i<n; ++i) {
            subSum = max(subSum + A[i], A[i]);
            result = max(result, subSum);
        }
        return result;
    }
};
