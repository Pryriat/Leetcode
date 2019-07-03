/*
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]

Note:
S will be a string with length between 1 and 12.
S will consist only of letters or digits.
*/

class Solution 
{
public:
    void proc(string &S,int pos,vector<string>& result)
    {
        if(pos==S.size())
        {
            result.push_back(S);
            return;
        }    
        if(S[pos]<'0'||S[pos]>'9')
        {
            S[pos]=tolower(S[pos]);
            proc(S,pos+1,result);
            S[pos]=toupper(S[pos]);
            proc(S,pos+1,result);
        }
        else
            proc(S,pos+1,result);
    }
    vector<string> letterCasePermutation(string S) 
    {
        vector<string> result;
        proc(S,0,result);
        return result;
    }
};
