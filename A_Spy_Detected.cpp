#include<iostream>
using namespace std;

int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int num1=-1,num2=-1,ans=-1;
        for(int i=0;i<n;i++)
        {
            if(num1==-1)
            {
                num1=arr[i];
            }
            else if(num1==arr[i])
            continue;
            else 
            num2=arr[i];
        }
        int cnt1=0,cnt2=0,ind1=-1,ind2=-1;
        for(int i=0;i<n;i++)
        {
            cnt1+=(num1==arr[i]);
            cnt2+=(num2==arr[i]);
            if(arr[i]==num1)
            ind1=i;
            if(arr[i]==num2)
            ind2=i;
        }
        if(cnt1<cnt2)
        cout<<ind1+1<<endl;
        else
        cout<<ind2+1<<endl;
    }
}