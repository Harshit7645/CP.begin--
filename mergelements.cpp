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

int dp[201][201];
int minCost(int i,int j,vector<int>&A){
    if(i==j) return 0;
    if(dp[i][j]!=-1)
      return dp[i][j];
   int tot = 0;
   int x = INT_MAX;
   for(int k =i;k<=j;k++ )
     tot+= A[k];
  for(int k =i+1;k<=j;k++){
      x = min(x,tot+minCost(i,k-1,A)+minCost(k,j,A));
  }
  return dp[i][j] = x;
}
int solve(vector<int>A)
{
    memset(dp,-1,sizeof(dp));
    return minCost(0,A.size()-1,A);
}
int main()
{
    cout<<solve({7, 3, 12, 17, 21, 18});
}   