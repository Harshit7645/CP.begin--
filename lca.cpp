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
bool isPresent(TreeNode* root,int x)
{
    if(root==NULL)
    return 0;
    if(root->val==x)
    return 1;
    return max(isPresent(root->left,x),isPresent(root->right,x));
}
TreeNode* LCA()
int solve(TreeNode* A,int B,int C)
{
    if (!A || root->val == B || root->val == C)
        return root;
    if((isPresent(A->left,B) && isPresent(A->right,C))||(isPresent(A->left,C) && isPresent(A->right,B)))
    return A->val;
    return max(solve(A->left,B,C),solve(A->right,B,C));
}
int main()
{
    //TreeNode* root=newNode(1);
}   