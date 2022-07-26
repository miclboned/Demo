#include <iostream>
#include <vector>
#include <queue>


using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

void Solution(TreeNode* root, vector<vector<int>>& ans)
{
    if(root==NULL) return ;
    queue<TreeNode*>q ;
    q.push(root);
    while(!q.empty())
    {
        int q_size=q.size();
        vector<int> res;
        for(int i=0;i<q_size;i++)
        {   
            TreeNode* currentNode=q.front();
            q.pop();
            res.push_back(currentNode->val);
            if(currentNode->left!=NULL)
                q.push(currentNode->left);
            if(currentNode->right!=NULL)
                q.push(currentNode->right);
        }
        ans.emplace_back(res);
    }
}

int main()
{
    TreeNode* root =new TreeNode(3);
    root->left=new TreeNode(8);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    vector<vector<int>> ans;
    Solution(root,ans);
    for(vector<vector<int>>::iterator iter=ans.begin();iter!=ans.end();iter++)
    {
        cout<<"[ ";
        for(vector<int>::iterator iter2=iter->begin();iter2!=iter->end();iter2++)
            cout<<*iter2<<" ";
        cout<<" ]";
        cout<<" ";
    }




    return 0;
}
