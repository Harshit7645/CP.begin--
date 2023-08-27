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

//ans vector
vector<int> ans;

//cuts vector
vector<int> ar;

//dp array
vector<vector<ll> > dp;

//parent array
vector<vector<int> > parent;

//solve for dp(l, r)
ll rec(int l, int r){
    //base case
    if(l+1>=r)return 0;

    //for memoisation
    ll &ret=dp[l][r];

    if(ret!=-1)return ret;


    ret=LLONG_MAX;
    int bestind;    //stores the best index

    for(int i=l+1; i<r; i++){
        //recurrence
        ll p=rec(l,i)+rec(i,r) + (ll)ar[r]-(ll)ar[l];

        //update best
        //note that we choose lexicographically smallest index
        //if multiple give same cost
        if(p<ret){
            ret=p;
            bestind=i;
        }
    }

    //store parent of (l, r)
    parent[l][r]=bestind;
    return ret;
}

//function for building solution
void back(int l, int r){
    //base case
    if(l+1>=r)return;

    //first choose parent of (l,r)
    ans.push_back(ar[parent[l][r]]);

    //call back recursively for two new segments
    //calling left segment first because we want lexicographically smallest
    back(l,parent[l][r]);
    back(parent[l][r],r);
}

vector<int> rodCut(int A, vector<int>B) {
    //insert A and 0
    B.push_back(A);
    B.insert(B.begin(),0);


    int n=B.size();
    ar.clear();
    for(int i=0; i<n; i++)
        ar.push_back(B[i]);

    //initialise dp array
    dp.resize(n);
    parent.resize(n);
    ans.clear();
    for(int i=0; i<n; i++){
        dp[i].resize(n);
        parent[i].resize(n);
        for(int j=0; j<n; j++)
            dp[i][j]=-1;
    }

    //call recurrence
    ll best=rec(0,n-1);
    // cout<<best<<" ";
    //build solution
    back(0,n-1);

    return ans;
}

int main()
{
    vector<int>ans=rodCut(6,{1,2,5});
    rep(i,0,ans.size())
    cout<<ans[i]<<" ";
}   