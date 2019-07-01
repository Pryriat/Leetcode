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

#pragma GCC optimize("Ofast")
static auto x = []() {std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return nullptr; }();
class Solution 
{
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        if(!root)
            return vector<vector<int>>{};
        vector<vector<int>> result;
        deque<Node*> tmp;
        int cs=1;
        tmp.push_back(root);
        while(cs)
        {
            vector<int> it;
            for(int x=0;x<cs;++x)
            {
                Node* p = tmp.front();
                tmp.pop_front();
                it.push_back(p->val);
                for(auto x:p->children)
                    tmp.push_back(x); 
            }
            result.push_back(it);
            cs=tmp.size();
        }
        return result;
    }
};
