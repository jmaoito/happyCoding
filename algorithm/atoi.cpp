/*************
  LeetCode String to Integer (atoi)

  Implement atoi to convert a string to an integer.

  Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

  Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

  Discussion:

  need to well handle overflow conditions

***************/
class Solution {
public:
    int atoi(const char *str) {
        int sign = 1;
        int ret = 0;
        int tmp = 0;
        int i = 0;
        
        while (str[i] == ' ') { i++; }  // handle preceding whitespace characters
        
        if (str[i] == '-' || str[i] == '+') {       // handle the optional sign
            sign = 1 - 2 * (str[i] == '-'); 
            i++;
        }
        while (str[i] >= '0' && str[i] <= '9') {    // only continued digits valid
            if ((tmp > INT_MAX / 10) || (tmp == INT_MAX / 10 && (str[i] - '0') > 7)) {  
                // > 7 to handle the tail of INT_MAX / 10. 8 and 9 will overflow for INT_MIN
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            tmp  = 10 * tmp + (str[i] - '0');
            i++;
        }
        return tmp * sign;
    }

};
