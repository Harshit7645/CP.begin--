#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
#define COUNT 10
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

void print2DUtil(TreeNode* root, int space)
{
    vector<pair<TreeNode*,int>>x;
    x.push_back({root,0});
    rep(i,0,x.size())
    {
        if(x[i].first->left)
        {
            x.push_back({x[i].first->left,x[i].second+1});
        }
        if(x[i].first->right)
        {
            x.push_back({x[i].first->right,x[i].second+1});
        }
    }
    rep(i,0,x.size())
    {
        cout<<x[i].first->val<<" "<<x[i].second<<" ";
        if(x[i].second!=x[i+1].second)
        cout<<"\n";
    }
}

int findMax(vector<int>&A,int start,int end)
{
    int maxind=start;
    rep(i,start,end+1)
    {
        if(A[i]>A[maxind])
        {
            maxind=i;
        }
    }
    return maxind;  
}
TreeNode* constructTreeleft(int lef,const vector<int>&A)
{
    if(lef<0)
    return NULL;
    TreeNode* x=newNode(A[lef]);
    x->left=constructTreeleft(lef-1,A);
    return x;
}
TreeNode* constructTreeright(int rig,const vector<int>&A)
{
    if(rig>=A.size())
    return NULL;
    TreeNode* x=newNode(A[rig]);
    x->right=constructTreeright(rig+1,A);
    return x;
}
TreeNode* sortedarraytoBST(const vector<int>A)
{
    ll n=A.size();
    TreeNode* root=newNode(A[n/2]);
    if(n==1)
    return root;
    root->left=constructTreeleft(n/2-1,A);
    root->right=constructTreeright(n/2+1,A);
    return root;
}
int main()
{
    vector<int>A={90, 228, 245, 290, 397, 471, 572, 649, 688, 710, 823, 829, 830, 859, 932, 939, 962};
    TreeNode* root=sortedarraytoBST(A);
    print2DUtil(root,0);
}