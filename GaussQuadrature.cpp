#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    return ((double)4)*pow(x, (double)3) - ((double)3)*x*x + ((double)2)*x - ((double)1);
}

double GaussQuad1(double a, double b)
{
    double e = 0;
    double w = 2;
    return ((b-a)*w*f((b+a)/(double)2 + (e*(b-a))/(double)2))/(double)2;
}

double GaussQuad2(double a, double b)
{
    double e = sqrt((double)1/(double)3);
    double w = 1;
    return ((b-a)*w*f((b+a)/(double)2 + (e*(b-a))/(double)2))/(double)2 + ((b-a)*w*f((b+a)/(double)2 + (-e*(b-a))/(double)2))/(double)2;
}

double GaussQuad3(double a, double b)
{
    double e1 = 0;
    double e2 = sqrt((double)3/(double)5);
    double w1 = (double)8/(double)9;
    double w2 = (double)5/(double)9;
    return ((b-a)*w2*f((b+a)/(double)2 + (e2*(b-a))/(double)2))/(double)2 + ((b-a)*w2*f((b+a)/(double)2 + (-e2*(b-a))/(double)2))/(double)2 + ((b-a)*w1*f((b+a)/(double)2 + (e1*(b-a))/(double)2))/(double)2;
}

double GaussQuad4(double a, double b)
{
    double e1 = sqrt((double)3/(double)7 - ((double)2*sqrt((double)6/(double)5))/(double)7);
    double e2 = sqrt((double)3/(double)7 + ((double)2*sqrt((double)6/(double)5))/(double)7);
    double w1 = ((double)18 + sqrt((double)30))/(double)36;
    double w2 = ((double)18 - sqrt((double)30))/(double)36;
    return ((b-a)*w2*f((b+a)/(double)2 + (e2*(b-a))/(double)2))/(double)2 + ((b-a)*w2*f((b+a)/(double)2 + (-e2*(b-a))/(double)2))/(double)2 + ((b-a)*w1*f((b+a)/(double)2 + (e1*(b-a))/(double)2))/(double)2 + ((b-a)*w1*f((b+a)/(double)2 + (-e1*(b-a))/(double)2))/(double)2;
}

int main()
{
    cout << GaussQuad2(0, 10);
}