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
        ll arr[n],b[n],c[n];
        rep(ii,0,n)
        {
            cin>>arr[ii];
            b[ii]=arr[ii];
            c[ii]=arr[ii];
        }
        if(is_sorted(arr,arr+n))
        {
            cout<<"0\n";
            continue;
        }
        ll f=0,dec=0,ans1=0,ans2=0,ans3=0;
        rep(i,0,n-1)
        {
            if(arr[i]>arr[i+1] && dec==0)
            {
                //f=1;
                dec++;
                ans1=ceil((double)(arr[i]+(arr[i+1]-arr[i])/2));
                ans2=arr[i]+(arr[i+1]-arr[i])/2;
                ans3=arr[i];
            }
        }
        rep(i,0,n)
        {
            arr[i]=abs(arr[i]-ans1);
            b[i]=abs(b[i]-ans2);
            c[i]=abs(c[i]-ans3);
        }
        if(is_sorted(arr,arr+n))
        cout<<ans1<<"\n";
        else if(is_sorted(b,b+n))
        cout<<ans2<<"\n";
        else if(is_sorted(c,c+n))
        cout<<ans3<<"\n";
        else
        cout<<"-1\n";
        //cout<<ans1<<" "<<ans2;
        // rep(i,0,n)
        // cout<<arr[i]<<" ";
        // cout<<endl;
        // rep(i,0,n)
        // cout<<b[i]<<" ";
        // cout<<endl;
    }
}