#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;

int arraySortedOrNot(ll arr[],ll n)
{
    if (n == 1 || n == 0)
        return 1;
    if (arr[n - 1] < arr[n - 2])
        return 0;
    return arraySortedOrNot(arr, n - 1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n],f=0;
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        if(n==1 || n==2)
        {
            PYES;
            continue;
        }
        else if(arraySortedOrNot(arr,n))
        {
            PYES;
            continue;
        }
        else
        {
            ll temp=0,f=1;
            rep(i,0,n-1)
            {
                if(f!=1)
                break;
                if(arr[i]<arr[i+1]){
                    f=0;
                while(arr[i+1]>=arr[i])
                {
                    if(i>=n-1)
                    break;
                    else
                    i++;
                    temp=i;
                }
                if(i==n-1)
                {
                    PYES;
                    break;
                }
                else
                {
                    PNO;
                }
                }
            }
            if(f)
            PYES;       
        }
    }
}