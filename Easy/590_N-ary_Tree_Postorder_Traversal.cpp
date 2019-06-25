/*
Given an n-ary tree, return the postorder traversal of its nodes' values.

For example, given a 3-ary tree:

 
![](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png)


 

Return its postorder traversal as: [5,6,3,2,4,1].

 
Note:

Recursive solution is trivial, could you do it iteratively?
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution 
{
public:
    vector<int> result;
    void solve(Node* root)
    {
        if(!root)
            return;
        if(root->children.size()>0)
            for(auto x:root->children)
                solve(x);
        this->result.push_back(root->val);
    }
    vector<int> postorder(Node* root) 
    {
        solve(root);
        return this->result;
    }
};
