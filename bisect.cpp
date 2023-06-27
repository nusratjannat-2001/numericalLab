
#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.000001
mt19937 rng(chrono::steady_clock::now().time_siNNnce_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)
// An example function whose solution is determined using
// Bisection Method. The function is x^3 - x^2  + 2
double func(double x)
{
   return x*x*x -2*x*x + 1;
}

// Prints root of func(x) with error of EPSILON
void bisection(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        // cout << "You have not assumed right a and b\n";
        return;
    }

    double c = a;
    while ((b-a) >= EPSILON)
    {
        // Find middle point
        c = (a+b)/2;

        // Check if middle point is root
        if (func(c) == 0.0)
            break;

        // Decide the side to repeat the steps
        else if (func(c)*func(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << "The value of root is : " << c;
    exit(0);
}

// Driver program to test above function
int main()
{
    // Initial values assumed
    for(int i = 0; i < 1000; i++){
    double a =rng(-10, 10), b = (10, 10);
    bisection(a, b);
    }
    return 0;
}
