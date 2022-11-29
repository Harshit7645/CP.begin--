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
        ll n;
        cin>>n;
        ll cnt[n];
        ll f=0;
        rep(i,0,n)
        {
            cin>>cnt[i];
        }
        rep(i,0,n-1)
        {
            if(cnt[i]!=cnt[i+1])
            {
                f=1;
                break;
            }
        }
        if(f==0)
        cout<<n<<endl;
        else{
            ll max=cnt[0],mai=0;
            rep(i,1,n)
            {
                if(cnt[i]>max)
                {
                    max=cnt[i];
                    mai=i;
                }
            }
            cout<<mai+1<<endl;
        }
    }
}