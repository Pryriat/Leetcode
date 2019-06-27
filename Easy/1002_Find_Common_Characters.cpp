/*
Share
Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

 

Example 1:
Input: ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:
Input: ["cool","lock","cook"]
Output: ["c","o"]
 

Note:
1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter
*/

class Solution 
{
public:
    vector<string> commonChars(vector<string>& A) 
    {
        int n = A.size();
        int tmp[n][26]={0};
        vector<string> result;
        for(int x=0;x<n;x++)
            for(auto y:A[x])
                tmp[x][int(y-'a')]++;
        for(int x=0;x<26;x++)
        {
            int tp = 100;
            for(int y=0;y<n;y++)
                tp = min(tp,tmp[y][x]);
            tmp[0][x]=tp;
        }            
        for(int x=0;x<26;x++)
            while(tmp[0][x]--)
                result.push_back(string(1,char(x+'a')));
        return result;
    }
};
