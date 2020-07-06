/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
*/
class Solution {
public:
       vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int length = digits.size();
        int carry = 1;
        int temp;
        for(int i = length - 1; i >= 0; --i)
        {
            temp = digits[i] + carry;
            carry = temp > 9 ? 1 : 0;
            temp %= 10;
            res.push_back(temp);
        }
        if(1 == carry)
        {
            res.push_back(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
