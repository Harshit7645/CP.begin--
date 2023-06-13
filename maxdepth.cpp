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
int ans;
int burntime(TreeNode * root,int leaf,int &dist) 
{
    if(root==NULL)
    return 0;
    if(root->val==leaf)
    {
        dist=0;
        return 1;
    }
    int ld=-1,rd=-1;
    int leftht=burntime(root->left,leaf,ld);
    int rightht=burntime(root->right,leaf,rd);
    if(ld!=-1)
    {
        dist=ld+1;
        ans=max(ans,dist+rightht);
    }
    if(rd!=-1)
    {
        dist=rd+1;
        ans=max(ans,dist+leftht);
    }
    return max(leftht,rightht)+1;
}
int solve(TreeNode* A)
{
    vector<pair<TreeNode*,int>>x;
    x.push_back({A,0});
    rep(i,0,x.size())
    {
        if(x[i].first->left)
        x.push_back({x[i].first->left,x[i].second+1});
        if(x[i].first->right)
        x.push_back({x[i].first->right,x[i].second+1});
    }
    int maxm=0;
    rep(i,0,x.size())
    {
        maxm=max(maxm,x[i].second);
    }
    return maxm+1;
}
int main()
{
    struct TreeNode* root = newNode(12);
    root->left = newNode(1);
    root->right = newNode(8);
     root->left->left = newNode(2);
     root->left->right = newNode(11);
     root->right->right = newNode(3);
    int ans=solve(root);
    cout<<ans;
}   