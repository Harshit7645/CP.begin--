#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
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
        cout<<x[i].first->val<<" \t"<<x[i].second<<" ";
        if(x[i].second!=x[i+1].second)
        cout<<"\n";
    }
}
void preorder(TreeNode* root,map<int,vector<int>>&m,int pos)
{
    if(root==NULL)
    return ;
    m[pos].push_back(root->val);
    preorder(root->left,m,pos+1);
    preorder(root->right,m,pos);
}
vector<int> solve(TreeNode* A)
{
    vector<int>ans;
    map<int,vector<int>>m;
    preorder(A,m,0);
    for(auto x:m)
    {
        rep(i,0,x.second.size())
        {
            ans.push_back(x.second[i]);
        }
    }
    return ans;
}
int main()
{
    TreeNode* A=newNode(1);
    A->left=newNode(2);
    A->right=newNode(3);
    A->left->right=newNode(5);
    A->right->left=newNode(4);
    A->left->right->left=newNode(6);
    A->left->right->right=newNode(7);
    A->left->right->left->right=newNode(8);
    //A->right->right=newNode(9);
    //print2DUtil(A,0);
    vector<int>v=solve(A);
    rep(i,0,v.size())
    {
        cout<<v[i]<<" ";
        //cout<<"\n";
    }
}