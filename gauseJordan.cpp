
#include <bits/stdc++.h>
using namespace std;
class  Gjordan
    {
  public:
      void convertToDiagonal(float a[4][5],int n)
      {
         int i,j,x,y,k;
    float ratio;
    for( i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
         if(j!=i)
         {
             ratio=a[j][i]/a[i][i];
             for(k=0;k<n+1;k++)
                a[j][k]=a[j][k] -( ratio * a[i][k]);

             //print the Matrix after changed row (Intermediate forms)
             //printf("Intermediate forms:\n");
             cout<<"intermiade form :"<<endl;
             for( x=0;x<n;x++)
             {
               for(y=0;y<n+1;y++)
               cout<<a[x][y]<<"  ";
               cout<<"\n";
             }
             cout<<"\n";

         }
      }
     }
      }
      public:
      void printUnknowns(float a[4][5],int n)
      {
     for(int i=0;i<n;i++)
     {
         cout<<"unknowns :"<<i<<"="<<a[i][n]/a[i][i]<<endl;          //0=1
                                                                   //1=3
                                                                   //2=5
     }
      }
    };


// Driver program
int main()
{
  Gjordan gjordan;
  int n;
  cin>>n;          //3
  float a[4][5];

  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n+1;j++)
      {
          cin>>a[i][j];        //1 1 1 9
                              //2 -3 4 13
      }                       //3 4 5 40
  }
  gjordan.convertToDiagonal(a,n);
   gjordan.printUnknowns(a,n);
	return 0;
}

