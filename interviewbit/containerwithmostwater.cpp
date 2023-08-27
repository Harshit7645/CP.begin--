#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

int maxArea(vector<int>height)
{
    int n=height.size();
    int l=0,r=n-1;
    int ans=min(height[0],height[n-1])*(n-1);
    while(l<r)
    {
        int area=min(height[l],height[r])*(r-l);
        ans=max(ans,area);
        if(height[l]<height[r])
        l++;
        else
        r--;
    }
    return ans;
}

int main()
{
    cout<<maxArea({1,8,6,2,5,4,8,3,7});
}   