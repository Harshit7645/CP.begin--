#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
#define all(x) x.begin(),x.end()
int M=1e9+7;

ll fact(ll n)
{
    ll ans=1;
    rep(i,1,n+1)
    {
        ans=(ans*i)%M;
    }
    return ans%M;
}

int main() {
    ll n,m;
    cin>>n>>m;
    ll a[n],b[m];   
    rep(i,0,n)
    {
        cin>>a[i];
    }
    rep(i,0,m)
    {
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    priority_queue<ll,vector<ll>,greater<ll>>pq;
    ll ind=0,tot=0;
    rep(i,0,m){
        while (ind<n && a[ind] < b[i]) {
            ++ind;
        }
        if (ind==n) {
            cout << -1 << endl;
            return 0;
        }
        tot+=a[ind];
        ind++;
    }
    cout<<tot<<endl;
}
