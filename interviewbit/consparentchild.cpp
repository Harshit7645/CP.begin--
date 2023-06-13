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
int solve(TreeNode* A)
{
    vector<TreeNode*>x;
    x.push_back(A);
    int ans=0;
    rep(i,0,x.size())
    {
        if(x[i]->left)
        {
            if(abs((x[i]->left->val)-(x[i]->val))==1)
            ans++;
            x.push_back(x[i]->left);
        }
        if(x[i]->right)
        {
            if(abs((x[i]->right->val)-(x[i]->val))==1)
            ans++;
            x.push_back(x[i]->right);
        }
    }
    // rep(i,0,x.size())
    // cout<<x[i]->val<<" ";
    return ans;
}
int main()
{
    struct TreeNode* root = newNode(1);
    root->left = newNode(5);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(2);
    //root->right->left = newNode(2);
    //root->right->right = newNode(7);
    //cout<<"hi";
    cout<<solve(root);
}   