
#include <bits/stdc++.h>
using namespace std;
class  SlLeast
    {
  public:
    float findAandB(float x[100],float y[100],int n)
    {
   float sum1=0,sum2=0,sum3=0,sum4=0,a,b,augmented_matrix[2][3];

   for(int i=0;i<n;i++)
   {
       sum1=sum1+x[i];
        sum2=sum2+y[i];
         sum3=sum3+x[i]*y[i];
          sum4=sum4+x[i]*x[i];
   }

   augmented_matrix[0][0]=n;
   augmented_matrix[0][1]=sum1;
   augmented_matrix[0][2]=sum2;
   augmented_matrix[1][0]=sum1;
   augmented_matrix[1][1]=sum4;
   augmented_matrix[1][2]=sum3;

   //print augmented matrix
   for(int i=0;i<2;i++)
   {
       for(int j=0;j<3;j++)
       {
            cout<<fixed<<setprecision(2);
          cout<< augmented_matrix[i][j]<<" ";
       }
       cout<<endl;
   }
   //find upper triangular matrix
  float ratio= augmented_matrix[1][0]/augmented_matrix[0][0];
   for(int i=0;i<3;i++)
   {
    augmented_matrix[1][i]=augmented_matrix[1][i]-(ratio*augmented_matrix[0][i]);
   }

   //  //printing Upper Triangular matrix

   for(int i=0;i<2;i++)
   {
       for(int j=0;j<3;j++)
       {
      cout<<fixed<<setprecision(2);
           cout<<augmented_matrix[i][j]<<" ";
       }
       cout<<endl;
   }

   b=augmented_matrix[1][2]/augmented_matrix[1][1];
   a=(augmented_matrix[0][2]-(augmented_matrix[0][1]*b))/augmented_matrix[0][0];
   cout<<endl;

   cout<<setprecision(2)<<"value of a: "<<a<<" "<<setprecision(2)<<"value of b: "<<b<<endl;    //.72  1.33
   cout<<endl;
   cout<<"equation : y="<<a<<"+"<<b<<"x"<<endl;        //y=0.72+1.33x

    }
    };


// Driver program
int main()
{
  SlLeast slleast;
  int n;       //5
  cin>>n;
 // float sum1=0,sum2=0,sum3=0,sum4=0,a,b;
  float x[n],y[n];
  for(int i=0;i<n;i++)
  {
      cin>>x[i];            //0 1 2 3 4
  }
  for(int i=0;i<n;i++)
  {
      cin>>y[i];          //1 1.8 3.3 4.5 6.3

  }
  slleast.findAandB(x,y,n);

  	return 0;
}

