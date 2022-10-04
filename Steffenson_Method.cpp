#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

double g(double x)
{
    return (double)1 + ((double)1)/x;
}

void SteffensonMethod(double guess0, double error)
{
    ofstream OUTPUT("./output.txt");
    long long int i = 0;
    long long int max_iter = 1000000000;
    while(1)
    {
        if(i > max_iter)
        {
            OUTPUT<<"ERROR: Could not complete operation\nIterations exceeded\nDiverging answer\n";
            OUTPUT<<"This is the end result by Steffenson method: "<<to_string(guess0);
            break;
        }
        double guess1 = g(guess0);
        double guess2 = g(guess1);
        double temp0 = (guess2*guess0 - guess1*guess1)/(guess2 - ((double)2)*guess1 + guess0);
        if(abs(temp0 - guess2) <= error)
        {
            OUTPUT<<"This is the root using Steffenson Method: "<<to_string(temp0);
            break;
        }
        i++;
        guess0 = temp0;
    }
    OUTPUT.close();
    return;
}

int main()
{
    double epsilon = 0.0000001;
    SteffensonMethod((double)2, epsilon);
    return 0;
}
