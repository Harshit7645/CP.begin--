#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        if(n==1||n==3)
        {
            cout<<"-1\n";
            continue;
            }
        if(n%2==0)
        {
            for(i=n;i>=1;i--)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else
        {
            if(n==5)
            {
                cout<<"5 4 1 2 3\n";
                continue;
            }
            for(i=n;i>=1;i--)
            {
                if(i==(n/2)+1)
                {
                    cout<<i-1<<" "<<i<<" ";
                    i--;
                }
                else
                cout<<i<<" ";
            }
            cout<<endl;
        }
    } 
}