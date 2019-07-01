/*
We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words. 

You may return the list in any order.

 

Example 1:
Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]

Example 2:
Input: A = "apple apple", B = "banana"
Output: ["banana"]
 

Note:
0 <= A.length <= 200
0 <= B.length <= 200
A and B both contain only spaces and lowercase letters.
*/
class Solution 
{
public:
    vector<string> uncommonFromSentences(string A, string B) 
    {
        map<string,int> a;
        vector<string> result;
        char* tmp=strtok(const_cast<char*>(A.c_str())," ");
        while(tmp)
        {
            a[string(tmp)]++;
            tmp=strtok(NULL," ");
        }
        tmp=strtok(const_cast<char*>(B.c_str())," ");
        while(tmp)
        {
            a[string(tmp)]++;
            tmp=strtok(NULL," ");
        }
        for(auto x:a)
            if(x.second==1)
                result.push_back(x.first);
        return result;
    }
};
