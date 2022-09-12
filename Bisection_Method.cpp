#include<bits/stdc++.h>
using namespace std;
double func(double x)
{
    return x*x + 4*x + 1;
}

void Bisection_Method(double guess1, double guess2, double epsilon)
{
    double i_g1 = func(guess1);
    double i_g2 = func(guess2);
    if(i_g1 <= epsilon)
    {
        cout<<"This is the root: "<<guess1<<'\n';
        return;
    }
    if(i_g2 <= epsilon)
    {
        cout<<"This is the root: "<<guess2<<'\n';
        return;
    }
    if(i_g1*i_g2 > 0)
    {
        cout<<"Give valid initial guesses\n";
        return;
    }
    while(1)
    {
        double temp = (guess1+guess2)/(double)2;
        double ans = func(temp);
        double f_g1 = func(guess1);
        double f_g2 = func(guess2);

        if(abs(ans) <= epsilon)
        {
            cout<<"This is the root: "<<temp<<'\n';
            break;
        }
        else if(ans*f_g1 < 0)
        {
            guess2 = temp;
        }
        else if(ans*f_g2 < 0)
        {
            guess1 = temp;
        }
    }
    return;
}
int main()
{
    double error = 0.0000001;
    Bisection_Method((double)(-3), (double)(-4), error);
}