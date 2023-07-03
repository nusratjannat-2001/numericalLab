#include<bits/stdc++.h>
using namespace std;
//#define EPSILON 0.0001

class Trapez
{
private:
 double y(double x)
 {
     return 1/(1+x*x);
 }

public:
    double root(double a,double b,int n)
    {
        double ans;
        double h=(b-a)/n;
        double s=y(a)+y(b);
        for(int i=1;i<n;i++)
        {
            s+=2*y(a+i*h);
        }
        ans= h/2*s;
        cout<<ans<<endl;
    }
};
int main()
{
   Trapez trapez;
    double x0,xn;
    int n;
    cin>>x0>>xn>>n;    // 0 1 6
    trapez.root(x0,xn,n);
  // cout<<"root :.4% "<<trapez.root(x0,xn,n);
}
