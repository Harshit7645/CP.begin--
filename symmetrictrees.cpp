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

int helper(TreeNode* lef,TreeNode* rig)
{
    if(lef==NULL || rig==NULL)
    return lef==rig;
    if(lef->val!=rig->val)
    return 0;
    return helper(lef->left,rig->right) && helper(rig->left,lef->right);
}
int isSymmetric(TreeNode* A)
{
    if(A==NULL)
    return 1;
    return helper;
}
int main()
{
    
}   