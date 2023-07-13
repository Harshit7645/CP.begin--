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
int subtree_sum[100005];

void dfs(int node,vector<vector<int>>&nodes,vector<int>&val,int parent)
{
    subtree_sum[node]=(subtree_sum[node]+val[node-1])%M;
    for(auto child:nodes[node])
    {
        if(parent==child)
        continue;
        dfs(child,nodes,val,node);
        subtree_sum[node]=(subtree_sum[node]+subtree_sum[child])%M;
    }
}
int solve(vector<int>&A,vector<vector<int>>&B)
{
    int n=A.size();
    memset(subtree_sum,0,sizeof(subtree_sum));
    vector<vector<int>>nodes(n+1);
    rep(i,0,n-1)
    {
        nodes[B[i][0]].push_back(B[i][1]);
        nodes[B[i][1]].push_back(B[i][0]);
    }
    dfs(1,nodes,A,0);
    ll ans=0;
    rep(i,2,n+1)
    {
        int ht1=subtree_sum[i];
        int ht2=subtree_sum[1]-ht1;
        ans=max(ans,(ht1%M*1ll*ht2%M)%M);
    }
    return ans;
}

int main()
{
    vector<int>A={42, 468, 335, 501, 170, 725, 479, 359, 963, 465, 706, 146, 282, 828, 962, 492, 996, 943, 828, 437, 392, 605, 903, 154, 293, 383, 422, 717, 719, 896, 448, 727, 772, 539, 870, 913, 668, 300, 36, 895, 704, 812, 323, 334, 674, 665, 142, 712, 254, 869, 548, 645, 663, 758, 38, 860, 724, 742, 530, 779, 317, 36, 191, 843, 289, 107, 41, 943, 265, 649, 447, 806, 891, 730, 371, 351, 7, 102, 394, 549, 630, 624, 85, 955, 757, 841, 967, 377, 932, 309, 945, 440, 627, 324, 538, 539, 119, 83, 930, 542, 834, 116, 640, 659, 705, 931, 978, 307, 674, 387, 22, 746, 925, 73, 271, 830, 778, 574, 98, 513, 987, 291, 162, 637, 356, 768, 656, 575, 32, 53, 351, 151, 942, 725, 967, 431, 108, 192, 8, 338, 458, 288, 754, 384, 946, 910, 210, 759, 222, 589, 423, 947, 507, 31, 414, 169, 901, 592, 763, 656, 411, 360, 625, 538, 549, 484, 596, 42, 603, 351, 292, 837, 375, 21, 597, 22, 349, 200, 669, 485, 282, 735, 54, 1000, 419, 939, 901, 789, 128, 468, 729, 894, 649, 484, 808, 422, 311, 618, 814, 515, 310, 617, 936, 452, 601, 250, 520, 557, 799, 304, 225, 9, 845, 610, 990, 703, 196, 486, 94, 344, 524, 588, 315};
    vector<vector<int>>B={};
    cout<<solve(A,B);
}   