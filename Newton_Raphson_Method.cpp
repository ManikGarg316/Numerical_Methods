#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x*x - (double)2*x + (double)1;
}

double f_der(double x)
{
    return (double)2*x - (double)2;
}

double NewtonRaphson(double guess, double error)
{
    int i=0;
    while(1)
    {
        if(i > 10000000)
        {
            break;
            // cout<<"ERROR: Iterations exceeded...\n";
            // exit(0);
            // return (double)-1;
        }
       
        double Temp = guess - (f(guess)/f_der(guess));
        if(abs(Temp - guess) <= error)
        {
            guess = Temp;
            break;
        }
        else
        {
            guess = Temp;
        }
        i++;
    }
    return guess;
}

int main()
{
    double epsilon = 0.0000001;
    cout << NewtonRaphson(0, epsilon);
}