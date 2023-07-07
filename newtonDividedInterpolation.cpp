
/* CPP Program to find approximation
of a ordinary differential equation
using euler method.*/
#include <bits/stdc++.h>
using namespace std;

class  Ndivider
{

public:
    float proterm(int i,float value,float x[])
    {
        float pro=1;
        for(int j=0;j<i;j++)
        {
            pro*=(value-x[j]);
        }
        return pro;
    }
public:
    void divideDiffTable(float x[],float y[][10],int n)
    {
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            y[j][i]=(y[j+1][i-1]-y[j][i-1])/(x[i+j]-x[j]);
        }
    }
    }


  float applyFormula(float value,float x[],float y[][10],int n)
    {
     float sum=y[0][0];
     for(int i=1;i<n;i++)
     {
         sum+=proterm(i,value,x)*y[0][i];
     }
     cout<<"sum :"<<sum<<endl;
    }
   void printDiffTable(float x[],float y[][10],int n)
   {
  for(int i=0;i<n;i++)
  {
      cout<<setprecision(4)<<x[i]<<"\t";
      for(int j=0;j<n-i;j++)
      {
          cout<<setprecision(4)<<y[i][j]<<"\t";
      }
      cout<<"\n";
  }
  cout<<endl;
   }
};
// Driver program
int main()
{
   Ndivider ndivider;
   int n;
   cin>>n;
   float value,sum,y[10][10],x[10];
   cin>>value;
   for(int i=0;i<n;i++)
   {
       cin>>x[i];                               // 4
   }                                          //  7
                                               //  5 6 9 11
                                            //12 13 14 16
   for(int i=0;i<n;i++)
   {
       cin>>y[i][0];
   }
   ndivider.divideDiffTable(x,y,n);
   ndivider.printDiffTable(x,y,n);
   ndivider.applyFormula(value,x,y,n);
	return 0;
}

