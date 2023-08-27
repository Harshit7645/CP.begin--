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

int solve(string A)
{
    int n=A.length();
    int cnt=0,ans=0;
    vector<int>gap;
    rep(i,0,n)
    {
        if(A[i]=='x')
        {
            gap.push_back(i-cnt);
            cnt++;
        }
    }
    if(cnt==n||cnt==0)
    return 0;
    int med_ind=(cnt-1)/2;
    int med_val=gap[med_ind];
    // rep(i,0,gap.size())
    // cout<<gap[i]<<" ";
    // cout<<"\n";
    // cout<<med_val<<""
    rep(i,0,gap.size())
    {
        ans+=abs(gap[i]-med_val);
        cout<<ans<<" ";
    }
    return ans;
}

int main()
{
    string A = "....x..xx...x..";
    int ans=solve(A);
    cout<<ans;
}   