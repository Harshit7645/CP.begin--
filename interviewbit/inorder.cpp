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
TreeNode* constructTree(vector<int>&A,int st,int end)
{
    if(st==A.size() || st>end   )
    return NULL;
    int maxind=findMax(A,st,end);
    TreeNode* root=newNode(A[maxind]);

    root->left=constructTree(A,st,maxind-1);
    root->right=constructTree(A,maxind+1,end);
    return root;
}

vector<int> inorder(TreeNode* A)
{
    stack<TreeNode*>s;
    vector<int>v;
    TreeNode* curr=A;
    s.push(A);
    while (curr != NULL || s.empty() == false) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        v.push_back(curr->val);
        curr = curr->right;
    }
    return v;
}
int main()
{
    
}