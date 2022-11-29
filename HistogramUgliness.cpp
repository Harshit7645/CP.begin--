#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    for(ll x=0;x<t;x++)
    {
        ll n,i,j,ans=0;
        cin>>n;
        ll arr[n],tot=0;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            if(i==0)
            tot+=arr[0];
            else 
            tot+=abs(arr[i]-arr[i-1]);
        }
        tot+=arr[n-1];
        for(i=0;i<n;i++)
        {
            if(i==0 && n>1 && arr[0]>arr[1]){
            tot-=abs(arr[0]-arr[1]);
            arr[0]=arr[1];
            }
            else if(i==n-1 && n>1 && arr[n-1]>arr[n-2]){
            tot-=abs(arr[n-1]-arr[n-2]);
            arr[n-1]=arr[n-2];
            }
            else if(i!=0 && i!=n-1)
            {
                if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
                {
                    tot-=abs(arr[i]-max(arr[i+1],arr[i-1]));
                    arr[i]=max(arr[i-1],arr[i+1]);
                }
            }
        }
        if(n==1)
        tot=arr[0];
        cout<<tot<<endl;
    }
}