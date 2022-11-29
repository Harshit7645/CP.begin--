#include <iostream>
using namespace std;
int main()
{
    int i,j,n,flag=0;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    n=s1.length();
    for(i=0;i<n;i++)
    {
        s1[i]=tolower(s1[i]);
        s2[i]=tolower(s2[i]);
    }
    for(i=0;i<n;i++)
    {
        if(s1[i]-s2[i]>0)
        {
            cout<<"1"<<endl;
            flag=1;
            break;
        }
        else if(s1[i]-s2[i]<0)
        {
            cout<<"-1"<<endl;
            flag=1;
            break;
        }
        
    }
    if(flag!=1)
    cout<<"0";
}