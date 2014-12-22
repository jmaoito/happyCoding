/***************
  LeetCode Reverse Words in a String

  Given an input string, reverse the string word by word.

  For example,
  Given s = "the sky is blue",
  return "blue is sky the".

  Clarification:
  A sequence of non-space characters constitutes a word.
  the input string contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
  multiple spaces between two words should be reduced to a single space in the reversed string.

  time complexity O(n) space complexity O(n)
********************/
class Solution {
public:
    void reverseWords(string &s) {
        string word, tmp;
        s += ' ';  // concatenate a space to the end of the string. otherwise, it will lost the last word.
        for (int i=0; i<s.size(); i++) {
            if (s[i] != ' ') {
                word += s[i];
            }
            else if (word[0]) {
                if (tmp[0])
                    word += ' ';
                tmp = word + tmp;
                word = "";
            }
        }
        s = tmp;
    }
};
