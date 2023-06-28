#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <string>
 
using namespace std;
long long dp[5005][5005][2];
long long solve(vector<int>&v,int i,int j,int x) {
    if(i<0 || j<0 || i>=v.size() || j>=v.size() || i>j) return 0;
    if(dp[i][j][x]!=-1) return dp[i][j][x];
    if(i==j) {
        if(x) {
            dp[i][j][x]=0;
        }
        else dp[i][j][x]=v[i];
        return dp[i][j][x];
    }
    if(x==0) {
        long long val1=v[i]+solve(v,i+1,j,1-x);
        long long val2=v[j]+solve(v,i,j-1,1-x);
        dp[i][j][x]=max(val1,val2);
    }
    else {
        long long val1=solve(v,i+1,j,1-x);
        long long val2=solve(v,i,j-1,1-x);
        dp[i][j][x]=min(val1,val2);
    }
    return dp[i][j][x];
}
int main() {
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++) cin>>v[i];  
    memset(dp,-1,sizeof(dp));
    long long ans = solve(v,0,n-1,0);
    cout<<ans;
    return 0;
}