#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
double func(double x)
{
    return x*x;
}

void Secant_Method(double guess0, double guess1, double epsilon)
{
    ofstream OUTPUT("./output.txt");
    while(1)
    {
        double i_g0 = func(guess0);
        double i_g1 = func(guess1);
        double new_guess = guess1 - i_g1*(guess1 - guess0)/(i_g1 - i_g0);
        double ans = func(new_guess);

        if(abs(ans) <= epsilon)
        {
            OUTPUT<<"This is the root using regular falsi method: "<<to_string(new_guess);
            break;
        }
        guess0 = guess1;
        guess1 = new_guess;
    }
    OUTPUT.close();
    return;
}
int main()
{
    double error = 0.0000001;
    Secant_Method((double)(0), (double)(1), error);
}