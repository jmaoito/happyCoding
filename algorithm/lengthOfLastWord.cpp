/**********************
  LeetCode Length of Last Word 

  Given a string s consists of upper/lower-case alphabets and empty space 
  characters ' ', return the length of last word in the string.

  If the last word does not exist, return 0.

  Note: A word is defined as a character sequence consists of non-space 
        characters only.

  For example, 
   Given s = "Hello World", return 5.

  Tags: String

  Discussion:
  If the string is finished with ' ', the length of previous word should be
  returned.

  time complexity O(n), space complexity O(1)
*************************/
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int num = 0;
        int i = 0;
        while (s[i] != '\0') {
            if (s[i] != ' ') ++num;
            else if (s[i+1] != ' ' && s[i+1] !='\0') 
                num = 0;
            ++i;
        }
        return num;
    }
};
