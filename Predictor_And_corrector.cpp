#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

double f(double x, double y)
{
    return -2.0*pow(10, -12)*(pow(y, 4.0) - pow(250.0, 4.0));
}

vector<pair<double, double>> PredictorAndCorrectorHeun(double x, double y, double h, double limit)
{
    vector<pair<double, double>> vals;
    int n = (limit - x)/h;
    vals.push_back({x, y});
    for(int i=0;i<n;i++)
    {
        double predicted_y = y + h*f(x, y);
        double corrected_y = y + (h/2)*(f(x, y) + f(x, predicted_y));
        x = x+h;
        y = corrected_y;
        vals.push_back({x, y});
    }
    return vals;
}


double AdamBashforth(double a, double b, double h, double x0, double y0)
{
    int n = (b-a)/h;
    double y1 = y0 + h*(f(x0, y0));
    double y2 = y1 + (h/2)*(3*f(x0+h, y1) - f(x0, y0));
    double y3 = y2 + (h/12)*(5*f(x0, y0) - 16*f(x0+h, y1) + 23*f(x0+2*h, y2));
    double y4;
    for(int i=0;i<n-3;i++)
    {
        y4 = y3 + (h/24)*(-9*f(x0, y0) + 37*f(x0+h, y1) - 59*f(x0+2*h, y2) + 55*f(x0+3*h, y3));
        cout << ' ' << y4;
        y1 = y2;
        y2 = y3;
        y3 = y4;
        x0 += h;
    }
    cout << x0 << ' ' << y4;
    return y4;
}

double AdamBashforthPnC(double a, double b, double h, double x0, double y0)
{
    int n = (b-a)/h;
    double y1_p = y0 + f(x0, y0);
    double y1_c = y0 + (h/2)*(f(x0, y0) + f(x0+h, y1_p));

    double y2_p = y1_c + (h/2)*(-f(x0, y0) + 3*f(x0+h, y1_c));
    double y2_c = y1_c + (h/12)*(-f(x0, y0) + 8*f(x0+h, y1_c) + 5*f(x0+2*h, y2_p));

    double y3_p = y2_c + (h/12)*(5*f(x0, y0) - 16*f(x0+h, y1_c) + 23*f(x0+2*h, y2_c));
    double y3_c = y2_c + (h/24)*(f(x0, y0) - 5*f(x0+h, y1_c) + 19*f(x0+2*h, y2_c) + 9*f(x0+3*h, y3_p));

    double y4_p;
    double y4_c;

    for(int i=0;i<n-3;i++)
    {
        y4_p = y3_c + (h/24)*(-9*f(x0, y0) + 37*f(x0+h, y1_c) - 59*f(x0+2*h, y2_c) + 55*f(x0+3*h, y3_c));
        y4_c = y3_c + (h/720)*(-19*f(x0, y0) + 106*f(x0+h, y1_c) - 264*f(x0+2*h, y2_c) + 646*f(x0+3*h, y3_c) + 251*f(x0+4*h, y4_p));

        y1_c = y2_c;
        y2_c = y3_c;
        y3_c = y4_c;
        x0 += h;
    }

    cout << x0 << ' ' << y4_c;
    return y4_c;
}

int main()
{
    AdamBashforth(0, 10, 1, 0, 2500);
    double x = pow(10, -7);
    cout << ' ' << x;
}