/*
Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.

 

Example 1:
Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

Example 2:
Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]
 

Note:
1 <= arr.length <= 10000
0 <= arr[i] <= 9
*/

class Solution1 /*no extra space but slow*/
{
public:
    void duplicateZeros(vector<int>& arr) 
    {
        int t = arr.size();
        for(int x=0;x<t-1;x++)
            if(!arr[x])
            {
                for(int y=t-1;y>x+1;y--)
                    arr[y]=arr[y-1];
                arr[++x]=0;
            }    
        return;
    }
};
class Solution /*use extra memory*/
{
public:
    void duplicateZeros(vector<int>& arr) 
    {
        vector<int> copy=arr;
        int t = arr.size();
        int pos=0;
        arr.clear();
        for(int x=0;pos<t;x++)
        {
            arr.push_back(copy[x]);
            if(!copy[x]&&pos<t-1)
            {
                arr.push_back(copy[x]);
                pos++;
            } 
            pos++;
        }    
        return;
    }
};
