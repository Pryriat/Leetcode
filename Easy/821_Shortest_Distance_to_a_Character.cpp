/*
Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:
Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 

Note:
S string length is in [1, 10000].
C is a single character, and guaranteed to be in string S.
All letters in S and C are lowercase.
*/

class Solution 
{
public:
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> tmp_pos;
        vector<int> result;
        string ts = string(1,C);
        int pos = S.find(ts);
        while(pos != S.npos)
        {
            tmp_pos.push_back(pos);
            pos++;
            pos = S.find(ts,pos);
        }  
        for(int x=0;x<S.size();x++)
        {
            int mi = 10000;
            for(auto p:tmp_pos)
                mi=min(mi,abs(p-x));
            result.push_back(mi);
        }
        return result;
    }
};
