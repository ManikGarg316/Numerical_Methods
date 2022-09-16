#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;

double f(double x)
{
    return x*x - (double)2*x + (double)1;
}

double f_der(double x)
{
    return (double)2*x - (double)2;
}

void NewtonRaphson(double guess, double error)
{
    ofstream OUTPUT("./output.txt");
    long long int i=0;
    long long int max_iter = 1000000000;
    while(1)
    {
        if(i > max_iter)
        {
            OUTPUT<<"ERROR: Could not complete operation\nIterations exceeded\nDiverging answer\n";
            OUTPUT<<"This is the end result by newton raphson method: "<<to_string(guess);
            break;
        }
       
        double temp = guess - (f(guess)/f_der(guess));

        if(abs(temp - guess) <= error)
        {
            OUTPUT<<"This is the root by newton raphson method: "<<to_string(temp);
            break;
        }
        guess = temp;
        i++;
    }
    OUTPUT.close();
    return;
}

int main()
{
    double epsilon = 0.0000001;
    NewtonRaphson((double)0, epsilon);
}