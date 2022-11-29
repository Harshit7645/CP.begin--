#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,i,j,k,temp;
    cin>>t;
    for(k=0;k<t;k++)
    {
        long long int n,c=0;
        cin>>n;
        long long int b[n],a[n];
        for(i=0;i<n;i++)
        {
            cin>>b[i];
            a[i]=i+1;
        }
        do
        {
            c=0;
            for(i=0;i<n;i++)
            {
                if(b[i]==(i+1)/a[i])
                {
                    c++;
                }
            }
            if(c==n)
            {
                for(i=0;i<n;i++){
                cout<<a[i]<<" ";}
                break;
            }
        } while(next_permutation(a,a+n));
        cout<<endl;
    }   
}