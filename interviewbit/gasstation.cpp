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
    vector<int>presum(n),postsum(n);
    int sum=0,fuel=0,ind=0;
    rep(i,0,n)
    {
        sum+=(A[i]-B[i]);
        fuel+=(A[i]-B[i]);
        if(fuel<0)
        {
            fuel=0;
            ind=i+1;
        }
    }
    if(sum>=0)
    return ind%n;
    return -1;
}

int main()
{
    cout<<solve({1,2,3,4,5},{3,4,5,1,2});
}   