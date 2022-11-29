#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,c=1,k;
    cin>>n;
    long long int arr[n][2];
    vector<pair<int,int>>v;
    for(i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
        v.push_back({arr[i][1],arr[i][0]});
    }
    sort(v.begin(),v.end());
    c=1;
    k=0;
    for(i=0;i<v.size();i++)
    {
        if(v[k].first<=v[i].second){
            c++;
            k=i;
        }
        
    }
    cout<<c;
    return 0;
}