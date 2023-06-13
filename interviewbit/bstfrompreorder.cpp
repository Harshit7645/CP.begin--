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
};
TreeNode* constructBST(vector<int>&A,int pos,int bound)
{
    if(pos==A.size()||A[pos]>bound)
    return NULL;
    TreeNode* root=newNode(A[pos++]);
    root->left=constructBST(A,pos,root->val);
    root->right=constructBST(A,pos,bound);
    return root;
}

TreeNode* solve(vector<int>A)
{
    ll n=A.size();
    if(n==0)
    return NULL;
    TreeNode* root=newNode(A[0]);
    if(1==n)
    return root;
    int ind=0;
    constructBST(A,ind,INT_MAX);
}
int main()
{

}