/*
Given words first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.

For each such occurrence, add "third" to the answer, and return the answer.



Example 1:
Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
Output: ["girl","student"]

Example 2:
Input: text = "we will we will rock you", first = "we", second = "will"
Output: ["we","rock"]
 

Note:
1 <= text.length <= 1000
text consists of space separated words, where each word consists of lowercase English letters.
1 <= first.length, second.length <= 10
first and second consist of lowercase English letters.
*/

/*
Reference:https://arstechnica.com/civis/viewtopic.php?f=20&t=767929
*/

class Solution 
{
public:
    vector<string> findOcurrences(string text, string first, string second) 
    {
        istringstream is(text);
        vector<string> tmp((istream_iterator<string>(is)),istream_iterator<string>());//必须在参数前加括号，否则会被解析为函数声明
        vector<string> result;
        for(int x=0;x<tmp.size()-2;x++)
            if(!tmp[x].compare(first) && !tmp[x+1].compare(second))
                result.push_back(tmp[x+2]);
        return result;
    }
};
