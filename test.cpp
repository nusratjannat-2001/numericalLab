//2nd degree polynomial only

#include <bits/stdc++.h>
using namespace std;
class CurvePolynomial
    {
  public:
    void convertToUpperTriangular(float a[3][4],int n)
{
    int i,j,x,y,k;
    float ratio;
    for( i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
         if(j>i)
         {
             ratio=a[j][i]/a[i][i];
            cout<<"ratio :"<<ratio;
             for(k=0;k<n+1;k++)
                a[j][k]=a[j][k] -( ratio * a[i][k]);
            // printf("Intermediate forms:\n");
             for( x=0;x<n;x++)
             {
               for(y=0;y<n+1;y++)
                 cout<<fixed<<setprecision(2)<<a[x][y];
               cout<<endl;
             }
              cout<<endl;
         }
      }
     }
}
   void ApplyBackSubstitution(float a[3][4],float value[],int n)
{
    int i,j;
    float sum;
    value[n-1]=a[n-1][n]/a[n-1][n-1];

    for(i=n-2;i>=0;i--)
    {
        sum=0;
        for(j=i+1;j<n;j++)
            sum=sum+a[i][j]*value[j];
        value[i] = (a[i][n]-sum)/a[i][i];
    }
}

    };


// Driver program
int main()
{
  CurvePolynomial polynomial;
  int n;       //3
  cin>>n;
    float sx=0,sy=0,sxy=0,sx2y=0,sx2=0,sx3=0,sx4=0,a,b,c,augmented_matrix[3][4];
  float x[n],y[n];
   float value[3];
  for(int i=0;i<n;i++)
  {
      cin>>x[i];            //0 1 2
  }
  for(int i=0;i<n;i++)
  {
      cin>>y[i];          //1 6 17

  }
 //polynomial.findAandBandC(x,y,n);

  for(int i=0;i<n;i++)
    {
        sx=sx+x[i];
        sy=sy+y[i];
        sxy=sxy+x[i]*y[i];
        sx2y=sx2y+x[i]*x[i]*y[i];
        sx2=sx2+x[i]*x[i];
        sx3=sx3+x[i]*x[i]*x[i];
        sx4=sx4+x[i]*x[i]*x[i]*x[i];
    }
    //Creating Augmented Matrix
    augmented_matrix[0][0]=n;
    augmented_matrix[0][1]=sx;
    augmented_matrix[0][2]=sx2;
    augmented_matrix[0][3]=sy;
    augmented_matrix[1][0]=sx;
    augmented_matrix[1][1]=sx2;
    augmented_matrix[1][2]=sx3;
    augmented_matrix[1][3]=sxy;
    augmented_matrix[2][0]=sx2;
    augmented_matrix[2][1]=sx3;
    augmented_matrix[2][2]=sx4;
    augmented_matrix[2][3]=sx2y;


   //print augmented matrix
   for(int i=0;i<3;i++)
   {
       for(int j=0;j<4;j++)
       {
            cout<<fixed<<setprecision(2);
          cout<< augmented_matrix[i][j]<<"  ";
       }
       cout<<endl;
   }

    //Applying Gauss Elimination Method to find a,b,c
    polynomial.convertToUpperTriangular(augmented_matrix,n);
    polynomial.ApplyBackSubstitution(augmented_matrix,value,n);

       cout<<fixed<<setprecision(2)<<"value[0] ="<<value[0]<<"value[1] ="<<value[1]<<"value[2] ="<<value[2];   //1 2 3
       cout<<endl;
       cout<<"equation : y="<<value[0]<<"+"<<value[1]<<"x+"<<value[2]<<"x^2"<<endl;     // 1 + 2x + 3x2
  	return 0;
}

