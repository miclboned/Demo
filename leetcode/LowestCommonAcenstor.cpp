#include <iostream>
#include <vector>


using namespace std;




struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :val(x),left(NULL),right(NULL){}

};


void dfs(TreeNode* root,TreeNode*p,TreeNode*q,vector<TreeNode*>& path1,vector<TreeNode*>& path2,bool findP,bool findQ)
{
    if(root==NULL||(findP&&findQ)) return ;
    if(!findP)
        path1.push_back(root);
    if(!findQ)
        path2.push_back(root);
    if(root==p)
        findP=true;
    if(root==q)
        findQ=true;
    dfs(root->left,p,q,path1,path2,findP,findQ);
    dfs(root->right,p,q,path1,path2,findP,findQ);
    if(!findP)
        path1.pop_back();
    if(!findQ)
        path2.pop_back();
}
TreeNode* solution(TreeNode* root,TreeNode*p,TreeNode*q)
{
    if(root==NULL) return NULL;
    if(root==p||root==q) return root;
    TreeNode* left=solution(root->left,p,q);
    TreeNode* right=solution(root->right,p,q);

    if(left&&right) return root;

    return (left!=NULL)?left:right;
}
void travel(TreeNode* root)
{
    if (root==NULL) return ;
    cout<<root->val<<" ";
    travel(root->left);
    travel(root->right);
    
}
int main()
{
    vector<TreeNode*> path1,path2;
    bool findP=false,findQ=false;
    TreeNode* p,*q;
    TreeNode* root=new TreeNode(3);
    p=root->left= new TreeNode(5);
    q=root->right=new TreeNode(1);
    root->left->left=new TreeNode(6);
    root->left->right=new TreeNode(2);
    root->left->right->left=new TreeNode(7);
    root->left->right->right=new TreeNode(4);
    root->right->left=new TreeNode(0);
    root->right->right=new TreeNode(8);
    cout<<q<<" "<<root->right<<endl;
    cout<<p<<" "<<root->left<<endl;
    TreeNode* dummy=root;
    //travel(dummy);
    /*dfs(root,p,q,path1,path2,findP,findQ);
    
    cout<<path2.size()<<endl;
    int i=0;
    while(i<path1.size()||i<path2.size())
    {
        if(path1!=path2)
            break;
        i++;
    }

    cout<<path1[i-1]->val<<endl;
    */
    cout<<solution(root,p,q)->val<<endl;
    return 0;
}
