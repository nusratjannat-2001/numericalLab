#include<bits/stdc++.h>
using namespace std;
//#define EPSILON 0.0001

class Simson
{
private:
 double func(double x)
 {
     return log(x);
 }

public:
    double root(double ll,double ul,int n)
    {
        //double ans=0;
        double h=(ul-ll)/n;
        double x[10],fx[10];

        for(int i=0;i<=n;i++)
        {
            x[i]=ll+i*h;
            fx[i]=func(x[i]);
        }

        double res=0;
        for(int i=0;i<=n;i++)
        {
            if(i==0||i==n)
                res+=fx[i];
            else if(i%2!=0)
               res+=4*fx[i];
            else
                res+=2*fx[i];
        }
        res=res*(h/3);
        cout<<"roots :" <<res<<endl;
    }
};
int main()
{
    Simson simson;
    double upper_limit,lower_limit;
    int n;
    cin>>upper_limit>>lower_limit>>n;    // 4 5.2 6
    simson.root(upper_limit,lower_limit,n);
  // cout<<"root :.4% "<<trapez.root(x0,xn,n);
}
