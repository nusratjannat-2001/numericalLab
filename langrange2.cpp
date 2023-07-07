#include<bits/stdc++.h>
using namespace std;

class LagrangeInterpolation
{
private:
    double x[100],y[100],xp,yp,p;
    int i,j,k;

public:
    LagrangeInterpolation()
    {
        i=0;
        yp=0.0;
        p=1.0;
    }

public:
    double addData(double a,double b)
    {
        x[i]=a;
        y[i]=b;
        i++;
    }

public:
    void findInterpolation(double xp,int n)
    {
        for(int i=0;i<n;i++)
        {
            p=1;
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                    p*=((xp-x[j])/(x[i]-x[j]));
            }

            yp+=(p*y[i]);
        }
    }

public:
    double getInterpolation()
    {
        return yp;
    }


};

int main()
{
    LagrangeInterpolation LI;
    int n;
    double x,y,xp;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        LI.addData(x,y);
    }
    cin>>xp;

    LI.findInterpolation(xp,n);
    double ans = LI.getInterpolation();

    cout<<"Value at "<<xp<<" is : "<<setprecision(10)<<ans;
    cout<<"\n";

    return 0;
}

