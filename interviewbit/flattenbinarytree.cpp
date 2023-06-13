#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
#define COUNT 10
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

struct TreeNode* newNode(int data)
{
    struct TreeNode* node
        = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
};

void print2DUtil(TreeNode* root, int space)
{
    vector<pair<TreeNode*,int>>x;
    x.push_back({root,0});
    rep(i,0,x.size())
    {
        if(x[i].first->left)
        {
            x.push_back({x[i].first->left,x[i].second+1});
        }
        if(x[i].first->right)
        {
            x.push_back({x[i].first->right,x[i].second+1});
        }
    }
    rep(i,0,x.size())
    {
        cout<<x[i].first->val<<" "<<x[i].second<<" ";
        if(x[i].second!=x[i+1].second)
        cout<<"\n";
    }
}
void preorder(TreeNode* root,vector<TreeNode*>&x)
{
    if(root==NULL)
    return ;
    x.push_back(root);
    preorder(root->left,x);
    preorder(root->right,x);
}
TreeNode* flatten(TreeNode* A)
{
    vector<TreeNode*>x;
    preorder(A,x);
    TreeNode* root=newNode(x[0]->val);
    TreeNode* node=root;
    rep(i,1,x.size())
    {
        node->right=newNode(x[i]->val);
        node=node->right;
    }
    return root;
}
int main()
{
    TreeNode* A=newNode(1);
    A->left=newNode(2);
    A->right=newNode(5);
    A->left->left=newNode(3);
    A->left->right=newNode(4);
    A->right->right=newNode(6);
    TreeNode* root=flatten(A);
    print2DUtil(root,0);
}