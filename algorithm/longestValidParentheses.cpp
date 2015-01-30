/**************************
  LeetCode Longest Valid Parentheses 

  Given a string containing just the characters '(' and ')', find the length 
  of the longest valid (well-formed) parentheses substring.

  For "(()", the longest valid parentheses substring is "()", which has 
  length = 2.

  Another example is ")()())", where the longest valid parentheses substring 
  is "()()", which has length = 4.

  Tags Dynamic Programming String

  Discussion:
  Dynamic programming, two passes scan (left to right, and right to left)
**********************/
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        int result = 0;
        int depth = 0;
        int start = -1;
        for (int i=0; i<len; i++) {
            if (s[i] == '(') ++depth;
            else {
                --depth;
                if (depth < 0) {
                    start = i;
                    depth = 0;
                }
                else if (depth == 0) result = max(result, i - start);
            }
        }
        
        depth = 0;
        start = len;
        for (int i=len-1; i>=0; i--) {
            if (s[i] == ')')  ++depth;
            else {
                --depth;
                if (depth < 0) {
                    start = i;
                    depth = 0;
                }
                else if (depth == 0) result = max(result, start - i);
            }
        }
        return result; 
    }
};
