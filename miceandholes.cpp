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

int solve(vector<int>A,vector<int>B)
{
    int n=A.size();
    int ans=0;
    sort(B.begin(),B.end());
    sort(A.begin(),A.end());
    rep(i,0,n)
    {
        ans=max(ans,abs(A[i]-B[i]));
    }
    return ans;
}
int main()
{
    cout<<solve({-4,2,3},{0,-2,4});
}   