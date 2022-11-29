#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main()
{
    long long int n,i,x=1,y,z,f=1;
    cin>>n;
    z=1000000007;
    for(i=1;i<=n;i++)
    f = (f*2) % z;
    cout<<f;

}