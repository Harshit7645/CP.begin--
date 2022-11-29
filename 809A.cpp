 #include<bits/stdc++.h>
 #include<iostream>
 using namespace std;
 int main()
 {
    int t;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        int n,m,i,j;
        cin>>n>>m;
        int arr[n];
        string str;
        set<int>s;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(i=0;i<m;i++)
        {
            str=str+'B';
        }
        for(i=0;i<n;i++)
        {
            if(arr[i]<=m+1-arr[i] && find(s.begin(),s.end(),arr[i]-1)==s.end())
            {
                str[arr[i]-1]='A';
                s.insert(arr[i]-1);
            }
            else if(arr[i]>=m+1-arr[i] && find(s.begin(),s.end(),m-arr[i])==s.end())
            {
                str[m-arr[i]]='A';
                s.insert(m-arr[i]);
            }
            else if(find(s.begin(),s.end(),m-arr[i])!=s.end() || find(s.begin(),s.end(),arr[i]-1)!=s.end())
            {
                str[arr[i]-1]='A';
                s.insert(arr[i]-1);
                str[m-arr[i]]='A';
                s.insert(m-arr[i]);
            }
        }
        cout<<str<<endl;
    }
 }