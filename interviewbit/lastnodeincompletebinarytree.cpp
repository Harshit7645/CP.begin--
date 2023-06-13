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

int getHeight(TreeNode * root) {
    int c = 0;
    while (root != NULL) {
        c++;
        root = root -> left;
    }
    return c;
}

int solve(TreeNode* A)
{
    int ans=1;
    vector<TreeNode*>x;
    x.push_back(A);
    int dl=0,dr=0;
    rep(i,0,x.size())
    {
        if(x[i]->left)
        {
            dl=getHeight(x[i]->left);
            x.push_back(x[i]->left);
        }
        if(x[i]->right)
        {
            dr=getHeight(x[i]->right);
            x.push_back(x[i]->right);
        }
        if(abs(dr-dl)>1)
        {
            ans=0;
            break;
            dl=0;
            dr=0;
        }
    }
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
    int ans=solve(root);
    cout<<ans;
}   