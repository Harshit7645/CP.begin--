#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
int main() {
    ll n,i;
    cin>>n;
    ll arr[n],min=0,max=0,mai=0,mii=0,ans=0,flag=0;
    cin>>arr[0];
    min=arr[0];
    max=arr[0];
    for(i=1;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>max){
        max=arr[i];    
        mai=i;
        }   
        else if(arr[i]<=min)
        {
            min=arr[i];
            mii=i;
        } 
    }
    ans=0;
    if(mai!=0)
    ans+=mai;
    if(mii!=n-1)
    ans+=n-mii-1;
    if(mai>mii)
    ans--;
    cout<<ans<<endl;
}
