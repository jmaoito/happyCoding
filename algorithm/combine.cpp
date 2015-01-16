/*****************
  LeetCode Combinations

  Given two integers n and k, return all possible combinations of k numbers
  out of 1 ... n.

  For example,
  If n = 4 and k = 2, a solution is:

  [
    [2,4],
    [3,4],
    [2,3],
    [1,2],
    [1,3],
    [1,4],
  ]

  Discussion:

  Method1: Deep First Search (recursive) It's also called backtracking
  C(n,k) = C(n-1, k) + C(n-1, k-1)

  time complexity O(n!), space complexity O(n)
**********************/
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> candidate;
        dfsCombine(n, k, 1, 0, candidate, result);
        return result;
    }
    
private:
    void dfsCombine(int n, int k, int start, int current, 
                vector<int> & candidate, vector<vector<int>> &result) {
        // start is the beginning number, current is the number of elements currently have
        if (current == k) {
            result.push_back(candidate);
            return;
        }
        
        for (int i=start; i<=n; ++i) {
            candidate.push_back(i);
            dfsCombine(n, k, i+1, current+1, candidate, result);
            candidate.pop_back();
        }
    }
};


/********************
  Method2: Iterative 

********************/
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> result;
        if (n < 1 || k < 1 || k > n) return result;
        vector<int> v = {1};
        bool toNext = false;
        while (!v.empty() && v.front() <= n - k + 1) {
	    // 
            if (v.size() == k) {
                result.push_back(v);
            }
            int x = v.back();
            if (x < n) {
                if (v.size() == k || toNext) v.pop_back();
                v.push_back(x + 1);
                toNext = false;
            } else {
                v.pop_back();
                toNext = true;
            }
        }
        return result;
    }
};
