#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,i;
    cin>>n>>m;
    long long int arr[n+1],bef[n+1],aft[n+1];
    for(i=1;i<n+1;i++)
    {
        cin>>arr[i];
    }
    for(int i = 2; i<=n; i++)
    {
        if(arr[i] >= arr[i-1])
        {
            bef[i] = bef[i-1];
        }
        else{
            bef[i] = bef[i-1] + arr[i-1]-arr[i];
        }
    }
    for(int i = n-1; i>=1; i--)
    {
        if(arr[i] >= arr[i+1])
        {
            aft[i] = aft[i+1];
        }
        else{
            aft[i] = aft[i+1] + arr[i+1]-arr[i];
            }
    }
    for(int i = 0; i<m; i++)
    {
        long long int l,r; cin >> l >> r;
        if(l <= r)
        {
            cout << bef[r]-bef[l] << '\n';
        }
        else
        {
            cout << aft[r]-aft[l] << '\n';
        }
    }
    return 0;
}