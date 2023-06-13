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

struct TreeNode* newNode(int val)
{
    struct TreeNode* node
        = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
vector<int>ans;
void Lower(TreeNode* root, int k){
    // Base Case
    if (root == NULL || k < 0) return;
 
    // If we reach a k distant node, print it
    if (k==0){
        ans.push_back(root->val);
        return;
    }
 
    // Recur for left and right subtrees
    Lower(root->left, k-1);
    Lower(root->right, k-1);
}
 
// Prints all nodes at distance k from a given target node.
// The k distant nodes may be upward or downward. This function
// Returns distance of root from target node, it returns
// -1 if target node is not present in tree rooted with root.
int Upper(TreeNode* root, TreeNode* target , int k){
    // Base Case 1: If tree is empty, return -1
    if (root == NULL) return -1;
 
    // If target is same as root. Use the downward function
    // to print all nodes at distance k in subtree rooted with
    // target or root
    if (root == target){
        Lower(root, k);
        return 0;
    }
 
    // Recur for left subtree
    int dl = Upper(root->left, target, k);
 
    // Check if target node was found in left subtree
    if (dl != -1){
        // If root is at distance k from target, print root
        // Note that dl is Distance of root's
        // left child from target
        if (dl + 1 == k)
            ans.push_back(root->val);
 
        // Else go to right subtree and print all k-dl-2
        // distant nodes Note that the right child is 2
        // edges away from left child
        else
            Lower(root->right, k-dl-2);
 
        // Add 1 to the distance and return value for parent calls
        return 1 + dl;
    }
 
    // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE
    // Note that we reach here only when node was
    // not found in left subtree
    int dr = Upper(root->right, target, k);
    if (dr != -1){
        if (dr + 1 == k)
            ans.push_back(root->val);
        else
            Lower(root->left, k-dr-2);
        return 1 + dr;
    }
 
    // If target was neither present in left
    // nor in right subtree
    return -1;
}

vector<int>solve(TreeNode* A,int B,int C)
{
    ans.clear();
    vector<TreeNode*>x;
    x.push_back(A);
    TreeNode* ptrB=NULL;
    rep(i,0,x.size())
    {
        if(x[i]->left)
        x.push_back(x[i]->left);
        if(x[i]->right)
        x.push_back(x[i]->right);
        if(x[i]->val==B)
        {
            ptrB=x[i];
            break;
        }
    }
    Upper(A,ptrB,C);
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
    root->right->right = newNode(7);
    vector<int>ans=solve(root,2,3);
    //cout<<root->right->right->val;
    rep(i,0,ans.size())
    cout<<ans[i]<<" ";
    //cout<<ans.size();
}   