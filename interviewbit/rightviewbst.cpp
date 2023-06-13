#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
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
void RightView(TreeNode* node,int *max_level,int level,vector<int>&x)
{
    if(node==NULL)
    {
        return ;
    }
    if(*max_level<level)
    {
        x.push_back(node->val);
        //cout<<*x.begin()<<" ";
        *max_level=level;
    }
    RightView(node->right,max_level, level + 1,x);
    RightView(node->left,max_level, level + 1,x);
}

vector<int>solve(TreeNode* A)
{
    vector<int>x;
    int max_level=0;
    RightView(A,&max_level,1,x);
    return x;
}
int main()
{
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->left->right = newNode(5);
    vector<int>x=solve(root);
    // rep(i,0,x.size())
    // cout<<x[i]<<" ";
    // cout<<x.size();
}   