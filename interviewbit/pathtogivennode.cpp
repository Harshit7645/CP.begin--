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

vector<int>solve(TreeNode* A,int B)
{
    vector<int>parent(100001,-1);
    parent[A->val]=0;
    vector<TreeNode*>x;
    x.push_back(A);
    ll ind=-1;
    rep(i,0,x.size())
    {
        if(x[i]->left)
        {
            x.push_back(x[i]->left);
            parent[x[i]->left->val]=x[i]->val;
        }
        if(x[i]->right)
        {
            x.push_back(x[i]->right);
            parent[x[i]->right->val]=x[i]->val;
        }
    }
    vector<int>ans;
    while(B!=0)
    {
        ans.push_back(B);
        B=parent[B];
    }
    reverse(ans.begin(),ans.end());
    return ans;
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
    vector<int>ans=solve(root,4);
    //cout<<"hi";
    rep(i,0,ans.size())
    cout<<ans[i]<<" ";
}   