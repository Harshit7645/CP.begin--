#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    for(long long int k=0;k<t;k++)
    {
        long long int n,i,j,sum1,sum2,ogcool=0,ct=0,pos,count1;
        cin>>n;
        vector<long long int>ht(n);
        for(i=0;i<n;i++)
        {
            cin>>ht[i];
        }
        long long int ans;
        for(i=1;i<n-1;i++)
        {
            if(ht[i]>ht[i-1] &&ht[i]>ht[i+1])
            ogcool++;
        }
        if(n%2==1)
        {
            ct=((n-2)/2) +1;
            ans=0;
            for(i=1;i<n-1;i+=2)
            {
                if(max(ht[i+1],ht[i-1])>=ht[i])
                ans+=max(ht[i+1],ht[i-1])-ht[i]+1;
            }
        }
        else{
            ct=(n-2)/2;
            ans=0;
            int pos=n-2;
            for (int i = 1; i < n-2; i+=2)
            {
                if(ht[i]>ht[i-1] and ht[i]>ht[i+1]) continue;
                else ans+=(max(ht[i-1],ht[i+1])-ht[i]+1);
            }
            count1=ans;
            while(pos!=0){
                pos=pos-2;
                if(ht[pos]<ht[pos+1] and ht[pos+1]>ht[pos+2]){
                    count1+=(max(ht[pos+3],ht[pos+1])-ht[pos+2]+1);
                }
                else{
                    count1-=(max(ht[pos],ht[pos+2])-ht[pos+1]+1);
                    if(ht[pos+2]> ht[pos+3] and ht[pos+2]>ht[pos+1]);
                    else count1+=(max(ht[pos+3],ht[pos+1])-ht[pos+2]+1);
                }
                ans=min(ans,count1);
            }
        }
        if(ogcool<ct)
        cout<<ans<<endl;
        else
        cout<<"0 \n";
    }
}