#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,k;
    cin>>t;
    for(k=0;k<t;k++)
    {
        int c=0;
        int a[2][2];
        for(i=0;i<2;i++)
        {
            for(j=0;j<2;j++)
            {
                cin>>a[i][j];
                if(a[i][j]==1)
                c++;
            }
        }
        if(c==0)
        cout<<0<<endl;
        else if(c==1 || c==2|| c==3)
        cout<<1<<endl;
        else if(c==4)
        cout<<2<<endl;
    }

}