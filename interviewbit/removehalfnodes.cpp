#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;

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
}
struct TreeNode* RemoveHalfNodes(struct TreeNode* root)
{
    if (root==NULL)
        return NULL;
    root->left  = RemoveHalfNodes(root->left);
    root->right = RemoveHalfNodes(root->right);
    if (root->left==NULL && root->right==NULL)
        return root;
    if (root->left==NULL)
    {
        struct TreeNode *new_root = root->right;
        free(root); // To avoid memory leak
        return new_root;
    }
    if (root->right==NULL)
    {
        struct TreeNode *new_root = root->left;
        free(root); // To avoid memory leak
        return new_root;
    }
    return root;
}
TreeNode* solve(TreeNode* A)
{
    // vector<TreeNode*>x;
    // x.push_back(A);
    // rep(i,0,x.size())
    // {
    //     if((x[i]->left && x[i]->right)||(!x[i]->left && !x[i]->right))
    //     x.push_back()
    // }
    struct TreeNode* root = RemoveHalfNodes(A);
    return root;
}
int main()
{
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    //cout<<"hi";
    rep(i,0,ans.size())
    cout<<ans[i]<<" ";
}   