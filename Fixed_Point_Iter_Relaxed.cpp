#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
// if relax parameter is 0, it becomes simple fixed point iteration
double g(double x)
{
    return (double)1 + ((double)1)/x;
}

void Fixed_Point_Iteration_Relax(double guess, double epsilon, double relaxParameter)
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

        double value = g(guess);
        
        // can be changed according to given in question
        double temp = relaxParameter*guess + (1-relaxParameter)*value;
        if(abs(temp - guess) <= epsilon)
        {
            OUTPUT<<"This is the root by fixed point iteration method: "<<to_string(temp);
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
    double error = 0.0000001;
    Fixed_Point_Iteration_Relax((double)(2), error, 0.2);
}