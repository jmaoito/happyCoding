/**************
  LeetCode Gray Code

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

Discussion:

The formula of converting natual binary code into gray code:
g0 = b0 , gi = bi ⊕ bi−1
where b0 is the most significant bit of the natural binary code

********************/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        const size_t size = 1 << n; // 2^n
        result.reserve(size);
        
        for(int i=0; i<size; i++)
            result.push_back(binaryToGray(i));
            
        return result;
    }
private:
/*
        The purpose of this function is to convert an unsigned
        binary number to reflected binary Gray code.
 
        The operator >> is shift right. The operator ^ is exclusive or.
*/
    static unsigned int binaryToGray(unsigned int n) {
        return n^(n>>1);
    }
};

