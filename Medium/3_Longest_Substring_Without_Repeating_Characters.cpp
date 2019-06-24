/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: "pwwkew"
Output: 3

Explanation: The answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.size() == 0)
            return 0;
        if(s.size() == 1)
            return 1;
        unsigned int result = 0;
        int pos = 0;
        for(int x = 0;x<s.size()-1;x++)
        {
            int y = x;
            bool a[128] = {false};
            short tmp = 0;
            pos = int(s[y]);
            while(!a[pos] && y<s.size())
            {
                a[pos] = true;
                tmp++;
                pos = int(s[++y]);
            }
            result = tmp>result?tmp:result;
        }
        return result;
    }
};
