#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"No\n"
#define PYES cout<<"Yes\n"
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
        vector<ll>p2;
        for(i=1;i<=n;i*=2)
        {
            p2.push_back(i);
        }
        reverse(p2.begin(),p2.end());
        ll sum=0,c=0;
        for(auto x:p2)
        {
            if(sum+x<=n){
            c++;
            sum+=x;
            }
            else if(sum==n)
            {
                break;
            }
        }
        cout<<c-1<<endl;
    }
}