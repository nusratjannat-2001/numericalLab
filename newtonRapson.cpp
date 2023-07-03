#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.01

class Nrapson
{
private:
    double func(double x)
    {
        return x*x*x-x*x+2;
    }
 double derivFunc(double x)
 {
     return 3*x*x-2*x;
 }
public:
    void root(double x)
    {
       double h=func(x)/derivFunc(x);
       while(abs(h)>=EPSILON)
       {
           h=func(x)/derivFunc(x);
           x=x-h;
       }
        cout<<"the root is : "<<x<<endl;
    }
};
int main()
{
   Nrapson nrapson;
    double x0;
    cin>>x0;
    nrapson.root(x0);
}
