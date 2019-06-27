/*
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/16/tree.png)

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Note:
Both of the given trees will have between 1 and 100 nodes.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    vector<int> t1;
    vector<int> t2;
    void check(TreeNode* root, vector<int>& bl)
    {
        if(!root)
            return;
        check(root->left,bl);
        if(!root->left && !root->right)
            bl.push_back(root->val);
        check(root->right,bl);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        check(root1,this->t1);
        check(root2,this->t2);
        int t = this->t1.size();
        if(this->t1.size()!=this->t2.size())
            return false;
        while(--t>=0)
            if(this->t1[t]!=this->t2[t])
                return false;
        return true;
    }
};
