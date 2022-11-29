#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
typedef vector<ll> vll;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>arr(n);
        rep(i,0,n)
        cin>>arr[i];
        ll c=n-1;
        ll ans;
        sort(arr.begin(),arr.end());
        ans=0,c=0;
        rep(i,0,n)
        {
            ll temp=-1;
            rep(j,1,n)
            {
                if(arr[j]>ans)
                {
                    temp=j-1;
                    break;
                }
            }
            if(temp!=-1){
            //ans=max(ans,temp);
            //arr[0]+=arr[temp];
            ans=max(ans,arr[temp]-ans+c++);
            arr.erase(arr.begin()+temp);
            //ans=max(ans,temp);
            }
            // arr[i+1]+=ans+c;
            // c++;
            //++
        }

        cout<<ans<<endl;
    } 
}