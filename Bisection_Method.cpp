#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;
double func(double x)
{
    return x*x;
}

void Bisection_Method(double guess1, double guess2, double epsilon)
{
    ofstream OUTPUT("./output.txt");
    double i_g1 = func(guess1);
    double i_g2 = func(guess2);
    if(abs(i_g1) <= epsilon)
    {
        OUTPUT<<"This is the root using bisection method: "<<to_string(guess1);
        OUTPUT.close();
        return;
    }
    if(abs(i_g2) <= epsilon)
    {
        OUTPUT<<"This is the root using bisection method: "<<to_string(guess2);
        OUTPUT.close();
        return;
    }
    if(i_g1*i_g2 > 0)
    {
        cout<<"Give valid initial guesses\n";
        OUTPUT.close();
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
            /*Put roots inside the output file*/
            OUTPUT<<"This is the root using bisection method: "<<to_string(temp);
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
    OUTPUT.close();
    return;
}
int main()
{
    double error = 0.0000001;
    Bisection_Method((double)(0), (double)(1), error);
}