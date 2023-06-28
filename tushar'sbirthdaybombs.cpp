#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

vector<int> solve(int A,vector<int>B)
{
    int n=B.size();
    int minm=INT_MAX,mini;
    rep(i,0,n)
    {
        minm=min(minm,B[i]);
    }
    rep(i,0,n)
    {
        if(minm==B[i])
        mini=i;
    }
    vector<int>ans;
    if(A%minm==0)
    {
        rep(i,0,A/minm)
        ans.push_back(mini);
        return ans;
    }
    vector<pair<int,int>>v;
    int prev=INT_MAX;
    rep(i,0,n)
    {
        if(prev>B[i])
        {
            v.push_back({i,B[i]});
            prev=B[i];
        }
    }
    int i=0,R=A;
    while(i<n)
    {
        if(R>=v[i].second && (1+(R-v[i].second)/minm)==R/minm)
        {
            ans.push_back(v[i].first);
            R-=v[i].second;
        }
        else
        i++;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int>ans=solve(9383,{17786, 11924, 22802, 13344, 10395, 10501, 16658, 16430, 2371, 15036, 18699, 20068, 22772, 13935, 5549, 8435, 14181, 5745, 5220, 20377, 2576, 6438, 15791, 21539, 22871, 15132, 24076, 3144, 13938, 4811, 9031, 23067, 8078, 23176, 11402, 18465, 20, 3051, 1238, 2382, 9430, 19928, 13793, 23546, 207, 19333, 23324, 14379, 16422, 3535, 1100, 18989, 9965, 16882, 6871, 24179, 7005, 22290, 2314, 20934, 2093, 11336, 10345, 1514, 855, 21738, 11322, 866, 16133, 3904, 19591, 554, 23823, 8376, 15443, 15373, 19052, 13759, 21096, 1817, 17285, 22187, 20797, 18593, 5412, 2660 });
    rep(i,0,ans.size())
    cout<<ans[i]<<" ";
}   