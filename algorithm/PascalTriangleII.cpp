/***************
  LeetCode Pascal's Triangle II

  Given an index k, return the kth row of the Pascal's triangle.

  For example, given k = 3,
  Return [1,3,3,1].

  Note:
  Could you optimize your algorithm to use only O(k) extra space?

  Discussion:

 * "k choose n" = k!/n!(k-n)!
 *  solution is not accepted due to the factorial will be overflow the integer type variable.

 Uses rolling array. time complexity O(n^2), space complexity O(n)

 **************/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result (rowIndex + 1, 1);
        for (int i=0; i<rowIndex+1; ++i) {
            for (int j=i-1; j>0; --j)
                result[j] += result[j-1];
        }
        return result;
    }
};
