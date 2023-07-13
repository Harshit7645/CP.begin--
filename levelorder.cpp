#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* newNode(int data)
{
    TreeNode* temp = new TreeNode(0);
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}
vector<vector<int>>solve(TreeNode* A)
{
    vector<pair<TreeNode*,int>>tree;
    vector<vector<int>>ans;
    tree.push_back({A,0});
    rep(i,0,tree.size())
    {
        if(tree[i].first->left)
        tree.push_back({tree[i].first->left,tree[i].second+1});
        if(tree[i].first->right)
        tree.push_back({tree[i].first->right,tree[i].second+1}); 
    }
    vector<int>temp;
    temp.push_back(tree[0].first->val);
    ans.push_back(temp);
    int c=1;
    rep(i,1,tree.size())
    {
        temp.clear();
        while(tree[i].second==c && i<tree.size())
        {
            temp.push_back(tree[i].first->val);
            i++;
        }
        i--;
        c++;
        ans.push_back(temp);
    }
    return ans;
}
int main()
{
    TreeNode* A=newNode(1);
    A->left=newNode(6);
    A->right=newNode(2);
    A->right->left=newNode(3);
    //A->right->right=newNode(7);
    vector<vector<int>>ans=solve(A);
    rep(i,0,ans.size())
    {
        rep(j,0,ans[i].size())
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}   