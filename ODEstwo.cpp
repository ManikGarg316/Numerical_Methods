#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

double f(double x, double y)
{
    // ofstream OUTPUT("./output.txt");
    return 4*pow(x, 3) + 3*x*x + 2*x + 1;
}

double RK4(double h, double initial_val, double start, double find)
{
    ofstream OUTPUT("./output.txt");
    int n = (find - start)/h;
    // cout << n << '\n';
    for(int i=0;i<n;i++)
    {
        double k1 = f(start, initial_val);
        double k2 = f(start+h/2, initial_val + (h*k1)/2);
        double k3 = f(start+h/2, initial_val + (h*k2)/2);
        double k4 = f(start+h, initial_val + h*k3);
        initial_val = initial_val + (h/6)*(k1+2*k2+2*k3+k4);
        start = start+h;
    }
    OUTPUT.close();
    return initial_val;
}
double RalstonMethod(double h, double initial_val, double start, double find)
{
    ofstream OUTPUT("./output.txt");
    int n = (find - start)/h;
    // cout << n << '\n';
    for(int i=0;i<n;i++)
    {
        double k1 = f(start, initial_val);
        double k2 = f(start+(3*h)/4, initial_val + (3*k1*h)/4);
        initial_val = initial_val + (h/3)*(k1+2*k2);
        start = start+h;
    }
    OUTPUT.close();
    return initial_val;
}

double MidpointMethod(double h, double initial_val, double start, double find)
{
    ofstream OUTPUT("./output.txt");
    int n = (find - start)/h;
    // cout << n << '\n';
    for(int i=0;i<n;i++)
    {
        double k1 = f(start, initial_val);
        double k2 = f(start+h/2, initial_val + (k1*h)/2);
        initial_val = initial_val + h*k2;
        start = start+h;
    }
    OUTPUT.close();
    return initial_val;
}

double HeunMethod(double h, double initial_val, double start, double find)
{
    ofstream OUTPUT("./output.txt");
    int n = (find - start)/h;
    // cout << n << '\n';
    for(int i=0;i<n;i++)
    {
        double k1 = f(start, initial_val);
        double k2 = f(start+h, initial_val + k1*h);
        initial_val = initial_val + (h/2)*(k1+k2);
        start = start+h;
    }
    OUTPUT.close();
    return initial_val;
}

double Euler(double h, double initial_val, double start, double find)
{
    ofstream OUTPUT("./output.txt");
    int n = (find - start)/h;
    // cout << n << '\n';
    for(int i=0;i<n;i++)
    {
        initial_val = initial_val + h*f(start, initial_val);
        start = start+h;
    }
    OUTPUT.close();
    return initial_val;
}

int main()
{
    // cout << Euler(10.0, 0.0, 0.0, 10.0) << '\n';
    // cout << Euler(1.0, 0.0, 0.0, 10.0) << '\n';
    // cout << Euler(0.1, 0.0, 0.0, 10.0) << '\n';
    // cout << "\n\n";
    // // cout << Euler(0.01, 0.0, 0.0, 10.0) << '\n';
    // // cout << Euler(0.001, 0.0, 0.0, 10.0) << '\n';
    // cout << HeunMethod(10.0, 0.0, 0.0, 10.0) << '\n';
    // cout << HeunMethod(1.0, 0.0, 0.0, 10.0) << '\n';
    // cout << HeunMethod(0.1, 0.0, 0.0, 10.0) << '\n';
    // cout << "\n\n";
    // cout << MidpointMethod(10.0, 0.0, 0.0, 10.0) << '\n';
    // cout << MidpointMethod(1.0, 0.0, 0.0, 10.0) << '\n';
    // cout << MidpointMethod(0.1, 0.0, 0.0, 10.0) << '\n';
    // cout << "\n\n";
    // cout << RalstonMethod(10.0, 0.0, 0.0, 10.0) << '\n';
    // cout << RalstonMethod(1.0, 0.0, 0.0, 10.0) << '\n';
    // cout << RalstonMethod(0.1, 0.0, 0.0, 10.0) << '\n';
    // cout << "\n\n";
    // cout << RK4(10.0, 0.0, 0.0, 10.0) << '\n';
    // cout << RK4(1.0, 0.0, 0.0, 10.0) << '\n';
    // cout << RK4(0.1, 0.0, 0.0, 10.0) << '\n';
}
