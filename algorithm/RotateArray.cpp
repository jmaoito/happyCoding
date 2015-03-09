/******************
  LeetCode Rotate Array 

  Rotate an array of n elements to the right by k steps.

  For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is 
  rotated to [5,6,7,1,2,3,4].

  Note:
  Try to come up as many solutions as you can, there are at least 3 different
  ways to solve this problem.

  Hint:
  Could you do it in-place with O(1) extra space?

  Related problem: Reverse Words in a String II

  Discussion:
  Solution 1. Make an extra copy and then rotate.
   Time complexity: O(n). Space complexity: O(n).
  Solution 2. Start from one element and keep rotating until we have
  rotated n different elements.
   Time complexity: O(n). Space complexity: O(1).
  Solution 3. Swap the last k elements with the first k elements.
   Time complexity: O(n). Space complexity: O(1).

**********************/
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        //if ((n <= 1) || (k <= 0)) return;
        
        // Make a copy of nums
        vector<int> numsCopy(n);
        for (int i = 0; i < n; i++) {
            numsCopy[i] = nums[i];
        }

        // Rotate the elements.
        for (int i = 0; i < n; i++) {
            nums[(i + k)%n] = numsCopy[i];
        }
    }
        
    void rotate(int nums[], int n, int k) {
        int cntRotated = 0;
        int start = 0;
        int curr = 0;
        int numToBeRotated = nums[0];
        int tmp = 0;
        // Keep rotating the elements until we have rotated n 
        // different elements.
        while (cntRotated < n) {
            do {
                tmp = nums[(curr + k)%n];
                nums[(curr+k)%n] = numToBeRotated;
                numToBeRotated = tmp;
                curr = (curr + k)%n;
                cntRotated++;
            } while (curr != start);
            // Stop rotating the elements when we finish one cycle, 
            // i.e., we return to start.

            // Move to next element to start a new cycle.
            start++;
            curr = start;
            numToBeRotated = nums[curr];
        }
    }

    void rotate(int nums[], int n, int k) 
    {
        for (; k = k%n; n -= k, nums += k)
        {
            // Swap the last k elements with the first k elements. 
            // The last k elements will be in the correct positions
            // but we need to rotate the remaining (n - k) elements 
            // to the right by k steps.
            for (int i = 0; i < k; i++)
            {
                swap(nums[i], nums[n - k + i]);
            }
        }
    }
};
