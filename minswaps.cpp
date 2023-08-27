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

int minSwaps(vector<int>arr, int n)
{
    vector<pair<int, int>>posn(n);
    rep(i,0,n)
    posn[i]={arr[i],i};
    sort(posn.begin(),posn.end());
    reverse(posn.begin(),posn.end());
    vector<bool>vis(n, false);
    int res = 0;
    rep(i,0,n)
    {
        if (vis[i])
        continue;
        else if(posn[i].second==i)
        continue;
        ll cycle = 0,j=i;
        while (!vis[j]) 
        {
            vis[j]=1;
            cycle++;
            j=posn[j].second;
        }
        if(cycle>0) 
        res+=(cycle-1);
    }
    return res;
}

int main()
{
    cout<<minSwaps({3,1,2,4},4);
}   