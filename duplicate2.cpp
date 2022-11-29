#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n),vec(n);
    set<int>s;
    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(i=n-1;i>=0;i--)
    {
        if(!(s.count(v[i])))
        {
            vec[i]=v[i];
            s.insert(v[i]);}
    }
    cout<<s.size()<<endl;
    for(i=0;i<n;i++)
    {
        if(vec[i]!=0)
        cout<<vec[i]<<" ";
    }
    return 0;
}