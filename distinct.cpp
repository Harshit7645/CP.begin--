#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    set <int> s;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        s.insert(arr[i]);
    }
    cout<<s.size();
}