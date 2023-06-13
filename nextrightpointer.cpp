#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };
struct TreeLinkNode* newNode(int data)
{
    // Allocate memory for new node
    struct TreeLinkNode* node
        = (struct TreeLinkNode*)malloc(sizeof(struct TreeLinkNode));
 
    // Assign data to this node
    node->val = data;
 
    // Initialize left and
    // right children as NULL
    node->left = NULL;
    node->right = NULL;
    return (node);
}
void solve(TreeLinkNode* A)
{
    vector<TreeLinkNode*>v;
    v.push_back(A);
    //cout<<"hi";
    ll c=1;
    rep(i,0,v.size())
    {
        if(i+1==pow(2,c)-1)
        {
            c++;
            v[i]->next=NULL;
        }
        else
        v[i]->next=v[i+1];
        if(v[i]->left!=NULL)
        v.push_back(v[i]->left);
        if(v[i]->right!=NULL)
        v.push_back(v[i]->right);
    }
    // rep(i,0,v.size())
    // {
    //     if(v[i]->next)
    //     cout<<v[i]->val<<" "<<v[i]->next->val<<endl;
    //     else
    //     cout<<v[i]->val<<" NULL\n";
    // }
    //cout<<v.size();
}
int main()
{
    struct TreeLinkNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    solve(root);
}   