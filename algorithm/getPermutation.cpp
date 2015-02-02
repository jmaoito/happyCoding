/***************************
  LeetCode Permutation Sequence

  The set [1,2,3,…,n] contains a total of n! unique permutations.

  By listing and labeling all of the permutations in order,
  We get the following sequence (ie, for n = 3):

  "123"
  "132"
  "213"
  "231"
  "312"
  "321"
  Given n and k, return the kth permutation sequence.

  Note: Given n will be between 1 and 9 inclusive.

  Tags: Backtracking, Math

  Discussuin: Cantor pairing function or call nextPermutation() k-1 times

  Assume the k-th permutation is a1a2a3...an, then if we remove a1, the rest of 
  the permutation will be a2a3...an, totally (n-1) elements. So,
  a1 = k/(n-1)! similarly,
  k2 = k%(n-1)!
  a2 = k2/(n-2)!
  ---
  kn-1 = kn-2%2!
  an-1 = kn-1/1!
  an = 0

  time complexity O(n), space complexity O(1);
************************/
class Solution {
public:
    string getPermutation(int n, int k) {
        string s(n, '0');
        for (int i=0; i<n; i++) {
            s[i] += i + 1;
        }
        return kth_permutation(s, k);
    }
private:
    int factorial(int n) {
        int result = 1;
        for (int i=1; i<=n; i++) {
            result *= i;
        }
        return result;
    }
    
    string kth_permutation(string & seq, int k) {
        string S(seq);
        int n = seq.size();
        string result;
        int base = factorial(n-1);
        --k;
        for (int i= n-1; i>0; --i) {
            char c = S[k/base];
            result.push_back(c);
            S.erase(S.begin() + k/base);
            k %= base;
            base /= i;
        }
        result.push_back(S[0]);
        return result;
    }
};
