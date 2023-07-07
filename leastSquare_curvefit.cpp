#include<bits/stdc++.h>
using namespace std;

class LeastSquareCurveFitting
{
private:
    double x[100],y[100],a0,a1,sumX,sumY,sumXX,sumXY;
    int i,j;

public:
    LeastSquareCurveFitting()
    {
        i=0;
        sumX=0.0;
        sumY=0.0;
        sumXX=0.0;
        sumXY=0.0;
    }

public:
    addData(double a,double b)
    {
        x[i]=a;
        y[i]=b;
        i++;
    }

public:
    void get_ans()
    {
        cout<<"Best straight  line fit is : \n";
        cout<<"Y = "<<setprecision(4)<<a0<<" + "<<setprecision(4)<<a1<<"x";
        cout<<"\n";
    }

public:
    void findLeastSquare(int n)
    {
        for(int i=0;i<n;i++)
        {
            sumX+=x[i];
            sumY+=y[i];
            sumXX+=(x[i]*x[i]);
            sumXY+=(x[i]*y[i]);
        }

        a1 = (n*sumXY - (sumX*sumY))/(n*sumXX-(sumX*sumX));
        a0 = (sumY/n)-a1*(sumX/n);
    }

};

int main()
{
    LeastSquareCurveFitting LSCF;
    int n;
    double x,y;

    cout<<"Enter the number of points : \n";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        LSCF.addData(x,y);
    }

    LSCF.findLeastSquare(n);
    LSCF.get_ans();

    return 0;
}
/*
Input:
4
0 -1
2 5
5 12
7 20

Output:
Y = -1.1381 + 2.8966x
*/

