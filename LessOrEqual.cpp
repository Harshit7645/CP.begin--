#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,k,i;
    cin>>n>>k;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    if(k<n && arr[k]!=arr[k-1] && arr[k-1]>0)
    cout<<arr[k-1]<<"\n";
    else if(k==n && arr[k-1]>0)
    cout<<arr[k-1]<<"\n";
    else if(k==0 && arr[0]-1>=1)
    cout<<arr[0]-1<<"\n";
    else
    cout<<"-1 \n";
}