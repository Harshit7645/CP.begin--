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

vector<vector<int>>solve(TreeNode* A)
{
    vector<int>ans;
    vector<TreeNode*>tree;
    tree.push_back(A);
    ans.push_back(A->val);
    TreeNode* p;
    //cout<<"hi";
    rep(i,0,tree.size())
    {
        if((ll)log2(i+1)%2==0)
        {
            if(tree[i]->right)
            {
                tree.push_back(tree[i]->right);
                ans.push_back(tree[i]->right->val);
            }
            if(tree[i]->left)
            {
                tree.push_back(tree[i]->left);
                ans.push_back(tree[i]->left->val);
            }
        }
        else
        {
            if(tree[i]->left)
            {
                tree.push_back(tree[i]->left);
                ans.push_back(tree[i]->left->val);
            }
            if(tree[i]->right)
            {
                tree.push_back(tree[i]->right);
                ans.push_back(tree[i]->right->val);
            }
        }
    }
    vector<vector<int>>finalans;
    ll n=ans.size(),c=0;
    rep(i,0,log2(n)+1)
    {
        if(c>n)
        break;
        vector<int>temp;
        ll j=0;
        while(j<pow(2,i) && c<n)
        {
            temp.push_back(ans[c++]);
            j++;
        }
        finalans.push_back(temp);
        if(c>n)
        break;
    }
    return finalans;
}
int main()
{
    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);
    vector<vector<int>>x=solve(root);
    rep(i,0,x.size())
    {
        rep(j,0,x[i].size())
        cout<<x[i][j]<<" ";
        cout<<endl;
    }
    //cout<<log2(2);
}