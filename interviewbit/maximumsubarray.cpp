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

int solve(vector<int>A)
{
        int n=A.size();
        int prod=1,ans=INT_MIN;
        rep(i,0,n)
        {
            prod*=A[i];
            ans=max(ans,prod);
            if(prod==0)
            prod=1;
        }
        prod=1;
        repr(i,n-1,0)
        {
            prod*=A[i];
            ans=max(ans,prod);
        }
        return ans;
}

int main()
{
    cout<<solve({2,3,-2,4,-5,2,-3,1,2,1});
}   