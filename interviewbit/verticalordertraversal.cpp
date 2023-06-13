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
vector<vector<int>> solve(TreeNode* A)
{
    map<ll,vector<ll>>ans;
    vector<vector<int>>v;
    vector<pair<TreeNode*,int>>x;
    if(A==NULL)
    return v;
    x.push_back({A,0});
    if(A->left == NULL && A->right==NULL)
    {
        vector<int>temp;
        temp.push_back(A->val);
        v.push_back(temp);
        return v;
    }
    rep(i,0,x.size())
    {
        if(x[i].first->left)
        x.push_back({x[i].first->left,x[i].second-1});
        if(x[i].first->right)
        x.push_back({x[i].first->right,x[i].second+1});
    }
    rep(i,0,x.size())
    {
        ans[x[i].second].push_back(x[i].first->val);
    }
    for(auto x:ans)
    {
        vector<int>temp;
        for(auto y:x.second)
        temp.push_back(y);
        v.push_back(temp);
    }
    return v;
}
int main()
{
    TreeNode* A=newNode(1);
    A->left=newNode(2);
    A->right=newNode(3);
    A->right->left=newNode(4);
    A->right->left->right=newNode(5);
    //A->right->right=newNode(9);
    vector<vector<int>>v=solve(A);
    rep(i,0,v.size())
    {
        rep(j,0,v[i].size())
        cout<<v[i][j]<<" ";
        cout<<"\n";
    }
}