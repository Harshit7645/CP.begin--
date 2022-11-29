#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,j,ct=0;
    double c;
    cin>>n;
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            c=sqrt(i*i + j*j);
            if(remainder(c,1)==0 && c<=n)
            ct++;
        }
    }
    cout<<ct;
}