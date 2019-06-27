/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/
class Solution 
{
public:
    string reverseWords(string s) 
    {
        string result;
        string tmp;
        char* p = strtok(const_cast<char*>(s.c_str())," ");
        while(p)
        {
            tmp = string(p);
            reverse(tmp.begin(),tmp.end());
            result+=tmp+" ";
            p=strtok(NULL," ");
        }    
        result.pop_back();
        return result;
    }
};
