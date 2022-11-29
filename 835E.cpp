#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
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
        ll arr[n],art[n],zeros[n],f=0,ans=0;
        rep(i,0,n)
        {
            cin>>arr[i];
            art[i]=arr[i];
        }
        ll c=0,inv=0;
        rep(i,0,n)
        {
            if(arr[i]==1)
            c++;
            else
            inv+=c;
        }
        //cout<<inv<<endl;
        // rep(i,0,n){
        //     zeros[i]=0;
        // }
        // ll c=0;
        // repr(i,n-1,0)
        // {
        //     if(arr[i]==0)
        //     c++;
        //     zeros[i]=c;
        // }
        // rep(i,0,n)
        // {
        //     if(arr[i]==1)
        //     ans+=zeros[i];
        // }
        f=0;
        rep(i,0,n)
        {
            if(f==0 && arr[i]==0)
            {
                arr[i]=1;
                f=1;
            }
        }
        ll c1=0,inv1=0;
        rep(i,0,n)
        {
            if(arr[i]==1)
            c1++;
            else
            inv1+=c1;
        }
        //cout<<inv<<endl;
        // rep(i,0,n){
        //     zeros[i]=0;
        // }
        // c=0;
        // repr(i,n-1,0)
        // {
        //     if(arr[i]==0)
        //     c++;
        //     zeros[i]=c;
        // }
        // ll ans1=0;
        // rep(i,0,n)
        // {
        //     if(arr[i]==1)
        //     ans1+=zeros[i];
        // }
        // //cout<<ans1<<endl;
         f=0;
         repr(i,n-1,0)
        {
            if(f==0 && art[i]==1)
            {
                art[i]=0;
                f=1;
            }
        }
        ll c2=0,inv2=0;
        rep(i,0,n)
        {
            if(art[i]==1)
            c2++;
            else
            inv2+=c2;
        }
        cout<<max(max(inv,inv1),inv2)<<endl;
        // rep(i,0,n){
        //     zeros[i]=0;
        // }
        // c=0;
        // repr(i,n-1,0)
        // {
        //     if(art[i]==0)
        //     c++;
        //     zeros[i]=c;
        // }
        // ll ans2=0;
        // rep(i,0,n)
        // {
        //     if(art[i]==1)
        //     ans2+=zeros[i];
        // }
        // cout<<max(max(ans1,ans),ans2)<<endl;
        //cout<<ans1<<endl;
    }
}