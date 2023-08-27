#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

 //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q)
{
    if(root==NULL || root==p || root==q)
    return root;
    if(root->val>p->val && root->val>q->val)
    return lowestCommonAncestor(root->left,p,q);
    else if(root->val<p->val && root->val<q->val)
    return lowestCommonAncestor(root->right,p,q);
    return root;
}
int main()
{
    
}   