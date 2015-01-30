/****************************
  LeetCode Valid Parentheses

  Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
  determine if the input string is valid.

  The brackets must close in the correct order, "()" and "()[]{}" are all valid 
  but "(]" and "([)]" are not.

  Tags: Stack, String

  Discussion:
  Use stack to pair the parentheses.

  time complexity O(n), space complexity O(n)
*****************************/
class Solution {
public:
    bool isValid(string s) {
        string left = "([{";
        string right = ")]}";
        stack<char> parenthese;
        for (int i=0; i<s.size(); i++) {
            if (left.find(s[i]) != string::npos) 
                parenthese.push(s[i]);
            else {
                if (parenthese.empty() || parenthese.top() != left[right.find(s[i])])
                    return false;
                else
                    parenthese.pop();
            }
        }
        return parenthese.empty();
    }
};
