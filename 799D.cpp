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
        string s;
        cin>>s;
        ll n,i;
        cin>>n;
        ll ans=0;
        ll arr[2880];
        rep(i,0,2880)
        {
            if(i>=1440)
            arr[i]=i-1440;
            else
            arr[i]=i;
        }
        map<ll,ll>pal,occur;
        rep(i,0,6)
        {
            pal[70*i]++;
        }
        rep(i,0,6)
        {
            pal[601+i*70]++;
        }
        pal[1202]++;
        pal[1272]++;
        pal[1342]++;
        pal[1412]++;
        ll ho=0,mi=0,mint=0;
        ho=stoi(s.substr(0,2));
        mi=stoi(s.substr(3,2));
        mint=ho*60+mi;
        i=mint;
        do
        {
            if(pal[arr[i]])
            occur[arr[i]]++;
            i+=n;
            i%=1440;

        }while(i!=mint);
        cout<<occur.size()<<endl;
        // for(auto x:pal)
        // {
        //     if(x.second==1)
        //     cout<<x.first<<" "<<x.second<<"\n";
        // }
        //cout<<s;
    }
}