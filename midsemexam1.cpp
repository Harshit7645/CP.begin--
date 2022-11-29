#include<iostream>
#include <bits/stdc++.h>
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
using namespace std;
vector<int> h;
int parent(int i)
{
    return ((i-1)/2);
}

int r_c(int i)
{
    return (2*i +2);
}

int l_c(int i)
{
    return 2*i + 1;
}

int minimum_ind(int left,int right)
{
    if(left<h.size() && right<h.size())
    {
        if(h[left]>h[right]){return right;}
        else{return left;}
    }
    else if(right < h.size()){return right;}
    else if(left < h.size()){return left;} 
    else{return -1;}
}

void heapify(int i)
{
    int min = minimum_ind(r_c(i),l_c(i));
    if(min == -1){return;}
    if(h[min]<h[i])
    {
        swap(h[min],h[i]);
        heapify(min);
    }
}

void print()
{
    cout << h[0] << " ";
    h[0] = h[h.size()-1];
    h.pop_back();
    while(h.size() >= 1)
    {
        heapify(0);
        print();
    }
}

int main()
{
    // vector<vector<int>> v;
    // vector<int> t;
    int temp;
    stringstream ssin;
    char ch='a';
    string s="";
    while(ch != '\n')
    {
        ch = getchar();
        if(ch == '$'){continue;}
        while(ch!=' ')
        {
            if(ch == '\n'){break;}
            s.push_back(ch);
            ch = getchar();
        }
        if(s != "")
        {
            ssin<<s;
            ssin>>temp;
            h.push_back(temp);
            s = "";
            ssin.clear();
        }
    }
    int n = h.size();
    for(int i=n/2;i>=0;i--)
    {
        heapify(i);
    }
    print();
}
