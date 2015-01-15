/************************
  LeetCode Next Permutation

  Implement next permutation, which rearranges numbers into the 
  lexicographically next greater permutation of numbers.

  If such arrangement is not possible, it must rearrange it as the lowest
  possible order (ie, sorted in ascending order).

  The replacement must be in-place, do not allocate extra memory.

  Here are some examples. Inputs are in the left-hand column and its 
  corresponding outputs are in the right-hand column.
  1,2,3 → 1,3,2
  3,2,1 → 1,2,3
  1,1,5 → 1,5,1

Discussion:
  for example 2,4,3,8,7,6,5,1
  1. find the first ascending digit from right to left of the number.
     3 < 8 > 7 > 6 > 5 > 1. Then 3 is the digit.
  2. from right to left, find the first digit which is larger than 3. 
     Which one is the next big digit in 8,7,6,5,1? 5! 
  3. swap them. Now the number becomes 2,4,5,8,7,6,3,1.
  4. reverse all the digits on the right of digit 5. then 8,7,6,,3,1 becomes 
     1,3,6,7,8. 
     The final answer is 2,4,5,1,3,6,7,8. 

  time complexity O(n), space complexity O(1)
**************************/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        const size_t len = num.size();
        for (int i=len-2; i>=0; --i) {
            if (num[i] < num[i+1]) {
                for (int j=len-1; j>i; --j) {
                    if (num[i] < num[j]) {
                        swap(num[i], num[j]);
                        reverse(num.begin()+i+1, num.end());
                        return;
                    }
                }
            }
        
        }
        reverse(num.begin(), num.end());
    }
};
