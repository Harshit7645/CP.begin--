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
void cousins(TreeNode* node,int wantlevel,int level,vector<int>&x,int B)
{
    if(node==NULL)
    {
        return ;
    }
    if(level==wantlevel)
    {
        x.push_back(node->val);
    }
    cousins(node->left,wantlevel,level+1,x,B);
    cousins(node->right,wantlevel,level+1,x,B);
}
int lvl=0;
void findlevel(TreeNode* A,int B,int level)
{
    if(A == NULL)
    return ;
    findlevel(A->left,B,level+1);
    if(A->val==B)
    {   
        lvl=level;
        return ;
    }
    findlevel(A->right,B,level+1);
}
vector<int>solve(TreeNode* A,int B)
{
    queue<pair<TreeNode* ,TreeNode*>> q;
    q.push({NULL,A});
    vector<int> ans;
    while(!q.empty())
    {
        vector<pair<int, int>> v;
        int sz=q.size();
        while(sz--)
        {
            TreeNode* nod=q. front().second;
            q.pop();
            if(nod->left) {q.push({nod,nod->left}); v.push_back({nod->val,nod->left->val});}
            if(nod->right) {q.push({nod,nod->right}); v.push_back({nod->val,nod->right->val});}
        }
        int parent=-1;
        for(auto it:v)
        {
            if(it.second==B) 
            {
                parent=it.first; 
                break;
            }
        }
        if (parent!=-1)
        {
            for(auto it:v)
            {
                if(it.first==parent) continue;
                ans.push_back(it.second);
            }
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
    root->right->right = newNode(7);
    vector<int>x=solve(root,4);
    rep(i,0,x.size())
    cout<<x[i]<<" ";
    //cout<<x.size();
}   