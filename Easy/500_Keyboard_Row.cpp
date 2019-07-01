/*
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

![](https://assets.leetcode.com/uploads/2018/10/12/keyboard.png)

Example:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
 

Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
*/
class Solution 
{
public:
    vector<string> findWords(vector<string>& words) 
    {
        vector<string> result;
        string data[3]={"qwertyuiop","asdfghjkl","zxcvbnm"};
        for(auto x:words)
        {
            bool fi=false;
            int pos=0;
            int y=0;
            for(pos;pos<3;pos++)
            {
                if(strchr(data[pos].c_str(),x[0])||\
                   strchr(data[pos].c_str(),x[0]+32)||\
                   strchr(data[pos].c_str(),x[0]-32))
                {
                    for(y;y<x.size();y++)
                        if(!strchr(data[pos].c_str(),x[y])&&\
                        !strchr(data[pos].c_str(),x[y]+32)&&\
                        !strchr(data[pos].c_str(),x[y]-32))
                            break;    
                    if(y==x.size())
                        result.push_back(x);
                    break;
                }    
            }
        }
        return result;
    }
};
