#include<bits/stdc++.h>
using namespace std;
#define MAX_ITER 1000000

class Fposition
{
private:
    double func(double x)
    {
        return x*x*x-x*x+2;
    }

public:
    void root(double a,double b)
    {
        if(func(a)*func(b)>=0)
        {
            cout<<"You have not assumed right a and b";
            return;
        }
        double c=a;
      for(int i=0;i<MAX_ITER;i++)
        {
            c=(a*func(b)-b*func(a))/(func(b)-func(a));
            if(func(c)==0.0)
                break;
            else if(func(c)*func(a)<0)
              b=c;
              else
              a=c;
        }
        cout<<"the root is : "<<c<<endl;
    }
};
int main()
{
   Fposition fposition;
    double a,b;
    cin>>a>>b;
    fposition.root(a,b);
}
