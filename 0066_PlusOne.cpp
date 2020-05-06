/*Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, 
and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> output;
        int c=1;
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(c)
            {
                digits[i]=digits[i]+c;
                if(digits[i]>9)
                {
                    output.push_back(0);                    
                }
                else
                {
                    c=0;
                    output.push_back(digits[i]);
                }
                    
            }  
            else
                output.push_back(digits[i]);
        }
        if(c)
            output.push_back(1);
        reverse(output.begin(),output.end());
        return output;
    }
};