/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        bool tmp = false;
        ListNode* q = new ListNode(0);
        ListNode* p = q;
        while(q)
        {  
            if(tmp)
                q->val = 1;
            tmp = false;
            if(l1)
                q->val += l1->val;
            if(l2)
                q->val += l2->val;
            if(q->val >=10)
            {
                q->val -= 10;
                tmp = true;
            }    
            q->next = ((l1&&l1->next)||(l2&&l2->next)||tmp)?new ListNode(0):NULL;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
            q = q->next;
        }
        return p;
    }
};