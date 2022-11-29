#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b)   for(int i=a;i<b;i++)
int main()
{
    ll t;
    cin>>t;
    for(ll x=0;x<t;x++)
    {
        ll n,i;
        cin>>n;
        vector <ll>all(n);
        for(i=0;i<n;i++)
        cin>>all[i];    
        sort(all.begin(),all.end(),greater<int>());   
        ll al=0,bob=0;
        rep(i,0,n)
        {
            if(i%2==0)
            {
                if(all[i]%2==0)
                {
                    al+=all[i];
                }
            }
            else
            {
                if(all[i]%2==1)
                bob+=all[i];
            }
        }
        if(al>bob)
            cout<<"Alice\n";
            else if(al<bob)
            cout<<"Bob\n";
            else
            cout<<"Tie\n";
    }
}
