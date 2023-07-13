#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
#define COUNT 10
int M=1e9+7;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

  struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

void printInorder(TreeNode* node)
{
    if (node == NULL)
        return;
 
    // First recur on left child
    printInorder(node->left);
 
    // Then print the data of node
    printf("%d ", node->val);
 
    // Now recur on right child
    printInorder(node->right);
}
TreeNode* constructBST(int l,int r,vector<int>&v)
{
    if(r<l)
    return NULL;
    int mid=(l+r)/2;
    TreeNode* node=new TreeNode(v[mid]);
    node->left=constructBST(l,mid-1,v);
    node->right=constructBST(mid+1,r,v);
    return node;
}
TreeNode* solve(ListNode* A)
{
    vector<int>v;    
    TreeNode* ans=NULL;
    ListNode* root=A;
    while(root!=NULL)
    {
        v.push_back(root->val);
        root=root->next;
    }
    // rep(i,0,v.size())
    // cout<<v[i]<<" ";
    int n=v.size();
    ans=constructBST(0,n-1,v);
    return ans;
}
int main()
{
    ListNode* root=new ListNode(1);
    root->next=new ListNode(2);
    root->next->next=new ListNode(3);
    root->next->next->next=new ListNode(4);
    root->next->next->next->next=new ListNode(5);
    root->next->next->next->next->next=new ListNode(6);
    root->next->next->next->next->next->next=new ListNode(7);
    TreeNode* ans=solve(root);
    printInorder(ans);
}   