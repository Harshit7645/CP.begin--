#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    for(long long int l=0;l<t;l++)
    {
        long long int x;
        vector<long long int>arr(3);
        cin>>x;
        cin>>arr[0]>>arr[1]>>arr[2];
        vector<long long int>v;
        if(x!=0)
        {
            v.push_back(x);
            if(arr[x-1]!=0)
            {
                v.push_back(arr[x-1]);
                if(arr[arr[x-1]-1]!=0)
                {
                    v.push_back(arr[arr[x-1]-1]);
                    if(arr[arr[arr[x-1]-1]-1]!=0)
                    v.push_back(arr[arr[arr[x-1]-1]-1]);
                }
            }
        }
        if(count(v.begin(),v.end(),1) && count(v.begin(),v.end(),2) && count(v.begin(),v.end(),3))
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}