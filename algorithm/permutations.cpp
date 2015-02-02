/************************
  LeetCode Permutations

  Given a collection of numbers, return all possible permutations.

  For example,
  [1,2,3] have the following permutations:
  [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

  Tags: Backtracking

  Discussion:
  calling nextPermutation() n-1 times

  time complexity O(n!), space complexity O(1)
**********************/
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());   // sort the input permutation
        vector<vector<int>> permutations;
        do {
            permutations.push_back(num);
        } while (nextPermutation(num));
        return permutations;
    }
private:
    bool nextPermutation(vector<int> &num) {
        const size_t len = num.size();
        for (int i=len-2; i>=0; --i) {
            if (num[i] < num[i+1]) {
                for (int j=len-1; j>i; --j) {
                    if (num[i] < num[j]) {
                        swap(num[i], num[j]);
                        reverse(num.begin()+i+1, num.end());
                        return true;
                    }
                }
            }
        
        }
        reverse(num.begin(), num.end());
        return false;   //no next greater permutation found
    }
};
