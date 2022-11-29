#include <iostream>
#include<string.h>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
int fact(int);


int main()
{
    int n,arr[26],i,j,k,t,num=1;
    char temp;
    string s,b;
    cin>>s;
    sort(s.begin(),s.end());
    n=s.length();
    for(i=0;i<26;i++)
    {
        arr[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<26;j++)
        {
            if(s[i]==(char)(j+97))
            arr[j]++;
        }
    }
    num=fact(n);
    for(i=0;i<26;i++)
    {
        num=num/fact(arr[i]);
    }
    cout<<num<<endl;
    k=0;
    string words[fact(n)];
    do
    {
        words[k]=s;
        k++;
    } while (next_permutation(s.begin(),s.end())); 
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            if(words[i]==words[j])
            {
                words[j]=="\0";
            }
        }
    }   
    for(i=0;i<num;i++)
    {
        cout<<words[i]<<endl;
    }
    return 0;

}
int fact(int n)
{
    int i,f=1;
    for(i=1;i<=n;i++)
    f=f*i;
    return f;
}