#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

TreeNode* pre=NULL;
void Solution1(TreeNode* root)
{
    if(root==NULL) return ;
    Solution1(root->right);
    Solution1(root->left);
    root->right=pre;
    root->left=NULL;
    pre=root;
}
void Solution2(TreeNode* root)
{
    if(root==NULL) return  ;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty())
    {
        TreeNode* cur=st.top();
        st.pop();
        if(cur->right!=NULL)
            st.push(cur->right);
        if(cur->left!=NULL)
            st.push(cur->left);
        if(!st.empty())
            cur->right=st.top();
        
        cur->left=NULL;
    }

}
void Solution3(TreeNode* root)
{
      if(root==NULL) return;
        TreeNode* cur=root; 
        TreeNode* prev=NULL;   
            
        while(cur)
        {
            if(cur->left)
            {
                prev=cur->left;
                while(prev->right) 
                    prev=prev->right;
                prev->right=cur->right;
                cur->right=cur->left;
                cur->left=NULL;
            }
            cur=cur->right;
        }
}
int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(5);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right->right=new TreeNode(6);
    //Solution1(root);
   // Solution2(root);
    Solution3(root);
    while(root)
    {
        cout<<root->val<<" ";
        root=root->right;
    }

    return 0;
}
