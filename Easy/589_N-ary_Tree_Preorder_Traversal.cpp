/*
Given an n-ary tree, return the preorder traversal of its nodes' values.

For example, given a 3-ary tree:

 

![](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png

 

Return its preorder traversal as: [1,3,5,6,2,4].

 

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
    void slove(Node* root)
    {
        if(!root)
            return;
        this->result.push_back(root->val);
        for(auto x:root->children)
            slove(x);
    }
    vector<int> preorder(Node* root) 
    {
        slove(root);
        return this->result;
    }
};
