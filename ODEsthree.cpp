#include <bits/stdc++.h>
using namespace std;

double f1(double x, double y, double t)
{
    return y;
}

double f2(double x, double y, double t)
{
    return -x + t;
}

void RK4(double h, double x0, double y0, double t0, double find)
{
    int n = ceil((find - t0)/h);
    // cout << n << '\n';
    for(int i=0;i<n;i++)
    {
        double k1_f1 = f1(x0, y0, t0);
        double k1_f2 = f2(x0, y0, t0);
        double k2_f1 = f1(x0 + (h*k1_f1)/2, y0 + (h*k1_f2)/2, t0 + h/2);
        double k2_f2 = f2(x0 + (h*k1_f1)/2, y0 + (h*k1_f2)/2, t0 + h/2);
        double k3_f1 = f1(x0 + (h*k2_f1)/2, y0 + (h*k2_f2)/2, t0 + h/2);
        double k3_f2 = f2(x0 + (h*k2_f1)/2, y0 + (h*k2_f2)/2, t0 + h/2);
        double k4_f1 = f1(x0 + (h*k3_f1), y0 + (h*k3_f2), t0 + h);
        double k4_f2 = f2(x0 + (h*k3_f1), y0 + (h*k3_f2), t0 + h);
        x0 = x0 + (h/6)*(k1_f1+2*k2_f1+2*k3_f1+k4_f1);
        y0 = y0 + (h/6)*(k1_f2+2*k2_f2+2*k3_f2+k4_f2);
        t0 = t0 + h;
    }
    cout << x0 << ' ' << y0 << ' ' << t0 << '\n';
    return;
}
void RalstonMethod(double h, double x0, double y0, double t0, double find)
{
    int n = ceil((find - t0)/h);
    // cout << n << '\n';
    for(int i=0;i<n;i++)
    {
        double k1_f1 = f1(x0, y0, t0);
        double k1_f2 = f2(x0, y0, t0);
        double k2_f1 = f1(x0 + (3*k1_f1*h)/4, y0 + (3*k1_f2*h)/4, t0 + (3*h)/4);
        double k2_f2 = f2(x0 + (3*k1_f1*h)/4, y0 + (3*k1_f2*h)/4, t0 + (3*h)/4);
        // double slopex = (h/3)*(k1_f1 + 2*k2_f1);
        // double slopey = 
        x0 = x0 + (h/3)*(k1_f1 + 2*k2_f1);
        y0 = y0 + (h/3)*(k1_f2 + 2*k2_f2);
        t0 = t0 + h;
    }
    cout << x0 << ' ' << y0 << ' ' << t0 << '\n';
    return;
}

void MidpointMethod(double h, double x0, double y0, double t0, double find)
{
    int n = ceil((find - t0)/h);
    // cout << n << '\n';
    for(int i=0;i<n;i++)
    {
        double k1_f1 = f1(x0, y0, t0);
        double k1_f2 = f2(x0, y0, t0);
        double k2_f1 = f1(x0 + (k1_f1*h)/2, y0 + (k1_f2*h)/2, t0 + h/2);
        double k2_f2 = f2(x0 + (k1_f1*h)/2, y0 + (k1_f2*h)/2, t0 + h/2);
        x0 = x0 + h*(k2_f1);
        y0 = y0 + h*(k2_f2);
        t0 = t0 + h;
    }
    cout << x0 << ' ' << y0 << ' ' << t0 << '\n';
    return;
}

void HeunMethod(double h, double x0, double y0, double t0, double find)
{
    int n = ceil((find - t0)/h);
    // cout << n << '\n';
    for(int i=0;i<n;i++)
    {
        double k1_f1 = f1(x0, y0, t0);
        double k1_f2 = f2(x0, y0, t0);
        double k2_f1 = f1(x0 + k1_f1*h, y0 + k1_f2*h, t0 + h);
        double k2_f2 = f2(x0 + k1_f1*h, y0 + k1_f2*h, t0 + h);
        x0 = x0 + (h/2)*(k1_f1 + k2_f1);
        y0 = y0 + (h/2)*(k1_f2 + k2_f2);
        t0 = t0 + h;
    }
    cout << x0 << ' ' << y0 << ' ' << t0 << '\n';
    return;
}

void Euler(double h, double x0, double y0, double t0, double find)
{
    int n = ceil((find - t0)/h);
    // cout << n << '\n';
    for(int i=0;i<n;i++)
    {
        double x = x0 + h*f1(x0, y0, t0);
        double y = y0 + h*f2(x0, y0, t0);
        x0 = x;
        y0 = y;
        t0 = t0 + h;
    }
    cout << x0 << ' ' << y0 << ' ' << t0 << '\n';
    return;
}

int main()
{
    Euler(10.0, 0.0, 0.0, 0.0, 10.0);
    Euler(1.0, 0.0, 0.0, 0.0, 10.0);
    Euler(0.1, 0.0, 0.0, 0.0, 10.0);
    cout << "\n\n";
    HeunMethod(10.0, 0.0, 0.0, 0.0, 10.0);
    HeunMethod(1.0, 0.0, 0.0, 0.0, 10.0) ;
    HeunMethod(0.1, 0.0, 0.0, 0.0, 10.0) ;
    cout << "\n\n";
    MidpointMethod(10.0, 0.0, 0.0, 0.0, 10.0);
    MidpointMethod(1.0, 0.0, 0.0, 0.0, 10.0) ;
    MidpointMethod(0.1, 0.0, 0.0, 0.0, 10.0) ;
    cout << "\n\n";
    RalstonMethod(10.0, 0.0, 0.0, 0.0, 10.0);
    RalstonMethod(1.0, 0.0, 0.0, 0.0, 10.0);
    RalstonMethod(0.1, 0.0, 0.0, 0.0, 10.0) ;
    cout << "\n\n";
    RK4(10.0, 0.0, 0.0, 0.0, 10.0);
    RK4(1.0, 0.0, 0.0, 0.0, 10.0);
    RK4(0.1, 0.0, 0.0, 0.0, 10.0);
}