#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<fixed<<setprecision(2);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
