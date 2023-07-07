
/* CPP Program to find approximation
of a ordinary differential equation
using euler method.*/
#include <bits/stdc++.h>
using namespace std;

class  Langrange
    {
  public:
    void root(float value,float x[],float y[],int n)
    {
        float result=0;
        for(int i=0;i<n;i++)
        {
            float term=y[i];
            for(int j=0;j<n;j++)
            {
                if(j!=i)
                term*=(value-x[j])/float(x[i]-x[j]);
            }
            result+=term;
        }
        cout<<"result :"<<result<<endl;
    }
    };


// Driver program
int main()
{
   Langrange langrange;
   int n;
   cin>>n;
   float value;
   cin>>value;
   float x[10],y[10];
   for(int i=0;i<n;i++)
   {
       cin>>x[i];
   }
   for(int i=0;i<n;i++)
   {
       cin>>y[i];
   }
   langrange.root(value,x,y,n);
	return 0;
}

