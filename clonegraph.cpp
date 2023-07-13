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

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

void dfs(UndirectedGraphNode* curr,UndirectedGraphNode* node,vector<UndirectedGraphNode*>&vis)
{
    vis[node->label]=node;
    for(auto ele:curr->neighbors)
    {
        if(vis[ele->label]==NULL)
        {
            UndirectedGraphNode* newnode=new UndirectedGraphNode(ele->label);
            (node->neighbors).push_back(newnode);
            dfs(ele,newnode,vis);
        }
        else
        (node->neighbors).push_back(vis[ele->label]);
    }
}
UndirectedGraphNode* solve(UndirectedGraphNode* node)
{
    if(node==NULL)
    return ;
    vector<UndirectedGraphNode*>ans;
    UndirectedGraphNode* root=new UndirectedGraphNode(node->label);
    vector<UndirectedGraphNode*>vis(100005,NULL);
    vis[root->label]=root;
    for(auto curr:node->neighbors)
    {
        if(vis[curr->label]==NULL)
        {
            UndirectedGraphNode* node=new UndirectedGraphNode(curr->label);
            (root->neighbors).push_back(node);
            dfs(curr,node,vis);
        }
        else
        root->neighbors.push_back(vis[node->label]);
    }
}
int main()
{
    
}   