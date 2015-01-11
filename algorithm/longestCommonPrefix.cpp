/**********************
  LeetCode Longest Common Prefix

  Write a function to find the longest common prefix string amongst an array 
  of strings.

  time complexity O(mn), space complexity O(1)
**************************/
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int len = strs.size();
        if (len == 0) return "";
        if (len == 1) return strs[0];
        
        string prefix = "";
        for (int i=0; i<strs[0].length(); ++i) {
            char ch = strs[0][i];
            for (int j=1; j<len; ++j) {
                if (ch != strs[j][i])
                    return prefix;
            }
            prefix.push_back(ch);
        }
        return prefix;
    }
};
