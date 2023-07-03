#include<bits/stdc++.h>
using namespace std;
//#define EPSILON 0.0001

float u_cal(float u,float n)
{
    float temp=u;
    for(int i=1;i<n;i++)
    {
        temp=temp*(u-i);

    }
    return temp;
}

int fact(int n)
{
    int f=1;
    for(int i=2;i<=n;i++)
    {
        f*=i;
    }
    return f;
}
int main()
{
    int n;
    cin>>n;
    float x[n];
    float y[n][n];
    for(int i=0;i<n;i++)
    {
       cin>>x[i];
    }
     for(int i=0;i<n;i++)
    {
       cin>>y[i][0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            y[j][i]=y[j+1][i-1]-y[j][i-1];
        }
    }
    for (int i = 0; i < n; i++) {
		cout << setw(4) << x[i]
			<< "\t";
		for (int j = 0; j < n - i; j++)
			cout << setw(4) << y[i][j]
				<< "\t";
		cout << endl;
	}

    float value;
    cin>>value;

    float sum=y[0][0];
    float u=(value-x[0])/(x[1]-x[0]);
    for(int i=1;i<n;i++)
    {
        sum+=(u_cal(u,i)*y[0][i])/fact(i);
    }
    cout<<"value :"<<sum<<endl;
}

	// Number of values given

	//float x[] = { 45, 50, 55, 60 };



	//y[0][0] = 0.7071;
	//y[1][0] = 0.7660;
	//y[2][0] = 0.8192;
	//y[3][0] = 0.8660;

	//float value = 52;



