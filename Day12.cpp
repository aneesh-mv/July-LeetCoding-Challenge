/*
Reverse bits of a given 32 bits unsigned integer.
Example 1:

Input: 00000010100101000001111010011100
Output: 00111001011110000010100101000000
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32>b = {n}; 
        int right = 0,left=31; 
        while(right < left){
			int t  = b[right];
            b[right++] = b[left];
            b[left--] = t;
        }
        return b.to_ulong();

    }
};
