#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

double solve(vector<int>nums1,vector<int>nums2)
{
    vector<int>req;
    int n=nums1.size();
    int m=nums2.size();
    ll i=0,j=0;
    while(i<n && j<m)
    {
        if(nums1[i]<=nums2[j])
        req.push_back(nums1[i++]);
        else
        req.push_back(nums2[j++]);
    }
    while(i<n)
    {
        req.push_back(nums1[i++]);
    }
    while(j<m)
    {
        req.push_back(nums2[j++]);
    }
    if((n+m)%2==0)
    {
        double ans;
        ans=(req[(n+m)/2]+req[(n+m)/2-1])/2.0;
        return ans;
    }
    else
    return req[(n+m)/2];
}

int main()
{
    cout<<solve({1,2},{3,4});
}   