/*
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:
Input: 5
Output: True
Explanation:
The binary representation of 5 is: 101

Example 2:
Input: 7
Output: False
Explanation:
The binary representation of 7 is: 111.

Example 3:
Input: 11
Output: False
Explanation:
The binary representation of 11 is: 1011.

Example 4:
Input: 10
Output: True
Explanation:
The binary representation of 10 is: 1010.
*/

class Solution 
{
public:
    bool hasAlternatingBits(int n) 
    {
        if(!n||n==1)
            return true;
        bitset<32> tmp(n);
        for(int x=31;x>=0;x--)
        {
            if(tmp[x])
            {
                for(int y=x;y>0;y--)
                    if(tmp[y]==tmp[y-1])
                        return false;
                break;
            }    
        }
        return true;
    }
};
