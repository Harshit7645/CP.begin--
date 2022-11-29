#include <iostream>
using namespace std;
int main()
{
    string s;
    long long int n,i,j,k,flag=0,c=0,t;
    cin>>s;
    n=s.length();
    char b[n];
    long long int a[26];
    for(i=0;i<26;i++)
    a[i]=0;
    for(i=0;i<n;i++)
    {
        for(j=65;j<91;j++)
        {
            if(s[i]==(char)(j))
            a[j-65]++;
        }
    }
    if(n%2==0)
    {
        flag=0;
        for(i=0;i<26;i++)
        {
            if(a[i]%2==1)
            {
                flag=1;
                break;
            }
        }
        if(flag!=1)
        {
            for(i=0;i<26;i++)
            {
                k=a[i]/2;
                for(j=0;j<k;j++)
                {
                    b[c]=(char)(i+65);
                    b[n-c-1]=(char)(i+65);
                    c++;
                }
            }
        }

    }
    int ct=0;
    if(n%2==1)
    {
        t=0;
        flag=0;
        for(i=0;i<26;i++)
        {
            if(a[i]%2==1)
            {
            ct++;
            t=i;
            }
            if(ct>1)
        {
            flag=1;
        break;
        }
        }
        
        if(flag!=1)
        {
            for(i=0;i<26;i++)
            {
                k=a[i]/2;
                for(j=0;j<k;j++)
                {
                    b[c]=(char)(i+65);
                    b[n-c-1]=(char)(i+65);
                    c++;
                }
            }
            b[n/2]=(char)(t+65);
        }
    }
    if(flag!=1)
    {
    for(j=0;j<n;j++)
    cout<<b[j];
    } 
    else
    cout<<"NO SOLUTION";   
    return 0;
    
}
