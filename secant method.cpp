#include <bits/stdc++.h>
using namespace std;
#define Epsilon 0.00001
class Secant
{
private:
 double f(double x)
 {
      return pow(x, 3) + 2*x*x - 1;

 }

 public:
 void root(double x1,double x2,double E)
 {
     float xm,x0,c;
     if(f(x1)*f(x2)<0)
{
         do
     {
         x0=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
         c=f(x1)*f(x0);
         x1=x2;
         x2=x0;

         if(c==0)
            break;
         xm=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
     }
     while((xm-x0)>=E);

        cout<<x0;
        exit(0);
}
     else
        cout<<"NO";
 }
};

int main() {

Secant secant;
   for(int i=0;i<1000;i++)
   {

      double x1,x2,E=0.001;
      x1=-9+rand()%10;
      x2=rand()%10;
       secant.root(x1,x2,E);
   }

    return 0;
}
