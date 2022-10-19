#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int sum;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int ans=a[0]+a[n-1];
        for(int j=0;j<n-1;j++)
        {
            sum=a[j]+a[j+1];
            ans=max(ans,sum);
        }
        cout<<ans<<endl;   
    }
}
