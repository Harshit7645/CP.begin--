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
vector<int>x;
void Inorder(TreeNode* node)
{
    if(node==NULL)
    {
        return ;
    }
    Inorder(node->left);
    x.push_back(node->val);
    Inorder(node->right);
}

int solve(TreeNode* A,int B)
{
    x.clear();
    Inorder(A);
    map<int,int>m;
    int n=x.size();
    rep(i,0,n)
    {
        m[x[i]]++;
    }
    rep(i,0,n)
    {
        if(m[x[i]] && m[x[i]-B])
        return 1;
    }
    return 0;
}
int main()
{
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout<<solve(root,4);
}   