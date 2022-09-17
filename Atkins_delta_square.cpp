#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
double g(double x)
{
    return (double)1 + ((double)1)/x;
}
void AtkinsDeltaSquare(double guess0, double error)
{
    ofstream OUTPUT("./output.txt");
    long long int i = 0;
    long long max_iter = 1000000000;
    double guess1 = g(guess0);
    double guess2 = g(guess1);
    double A0 = (guess2*guess0 - guess1*guess1)/(guess2 - ((double)2)*guess1 + guess0);
    while(1)
    {
        if(i > max_iter)
        {
            OUTPUT<<"ERROR: Could not complete operation\nIterations exceeded\nDiverging answer\n";
            OUTPUT<<"This is the end result by Atkin's Delta Square method: "<<to_string(guess);
            break;
        }
        double temp = g(guess2);
        guess0 = guess1;
        guess1 = guess2;
        guess2 = temp;
        double A1 = (guess2*guess0 - guess1*guess1)/(guess2 - ((double)2)*guess1 + guess0);
        if(abs(A1 - A0) <= error)
        {
            OUTPUT<<"This is the root using Atkin's Delta Square Method: "<<to_string(A1);
            break;
        }
        else
        {
            A0 = A1;
        }
        i++;
    }
    OUTPUT.close();
    return;
} 

int main()
{
    double epsilon = 0.0000001;
    AtkinsDeltaSquare((double)2, epsilon);
}