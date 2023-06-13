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

TreeNode* invert(TreeNode* A)
{
    vector<TreeNode*>x;
    if(A==NULL)
    return A;
    x.push_back(A);
    rep(i,0,x.size())
    {
        if(x[i]->left && x[i]->right)
        {
            TreeNode* temp=x[i]->left;
            x[i]->left=x[i]->right;
            x[i]->right=temp;
            x.push_back(x[i]->left);
            x.push_back(x[i]->right);
        }
        else if(x[i]->right)
        {
            x[i]->left=x[i]->right;
            x.push_back(x[i]->left);
        }
        else if(x[i]->left)
        {
            x[i]->right=x[i]->left;
            x[i]->left=NULL;
            x.push_back(x[i]->right);
        }
    }
    return A;
}
int main()
{
    TreeNode* 
}   