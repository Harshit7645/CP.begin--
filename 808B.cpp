#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    for(long long int k=0;k<t;k++)
    {
        long long int n,l,r,i,j,temp=0;
        cin>>n>>l>>r;
        long long int arr[n];
        set<int>s1;
        for(i=0;i<n;i++)
        arr[i]=-1;
        for(i=0;i<n;i++)
        {
            j=l;
            for(;j<=r;j++)
            {
                if(s1.find(gcd(i+1,j))==s1.end())
                {
                    arr[i]=j;
                    s1.insert(gcd(i+1,j));
                }
            }
        }
        int flag=0;
        for(i=0;i<n;i++)
        {
            if(arr[i]==-1)
            {
                flag=1;
                break;
            }
        }
        if(flag!=1)
        {
            cout<<"YES"<<endl;
            for(i=0;i<n;i++)
            cout<<arr[i]<<" ";
            cout<<endl;
        }
        else
        cout<<"NO"<<endl;
    }
}