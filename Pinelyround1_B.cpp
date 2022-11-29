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
        ll n;
        cin>>n;
        set<ll>s;
        vector<ll>arr(n);
        rep(i,0,n){
        cin>>arr[i];
        s.insert(arr[i]);
        }
        vector<ll>visit(n);
        ll ans=0,i=0;
        if(s.size()==1)
        {
            cout<<1<<endl;
            continue;
        }
        else if(s.size()>2)
        {
            cout<<n<<"\n";
        }
        else
        {
            cout<<1+(n/2)<<endl;
        }
    }
}