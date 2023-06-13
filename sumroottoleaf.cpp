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
int sum(TreeNode* root, int val){
    if(root == NULL)
        return 0;
    val = (((val)%1003*10)%1003 + (root->val)%1003)%1003;
    if(root->left == NULL && root->right == NULL)
        return val; 
    return (sum(root->left, val)%1003 + sum(root->right, val)%1003)%1003;
}
int main()
{
    struct TreeNode* root = newNode(12);
    root->left = newNode(1);
    root->right = newNode(8);
     root->left->left = newNode(2);
     root->left->right = newNode(11);
     root->right->right = newNode(3);
    int ans=solve(root);
    cout<<ans;
}   