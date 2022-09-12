#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void forward_eli(vector<vector<double>> &A, vector<double> &B)
{
    int n = A.size();
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            double fact = A[j][i]/A[i][i];
            for(int k=i+1;k<n;k++)
            {
                A[j][k] = A[j][k] - fact*A[i][k];
            }
            B[j] = B[j] - fact*B[i];
        }
    }
}

void backward_eli(vector<vector<double>> &A, vector<double> &B)
{
    int n = A.size();
    double X[n];
    X[n-1] = B[n-1]/A[n-1][n-1];
    for(int i=n-2;i>=0;i--)
    {
        double sum = B[i];
        for(int j=i+1;j<n;j++)
        {
            sum = sum - A[i][j]*X[j];
        }
        X[i] = sum/A[i][i];
    }
}

int main()
{
    vector<vector<double>> A
    {
        {-2,1,0,0,0},
        {1,-2,1,0,0},
        {0,1,-2,1,0},
        {0,0,1,-2,1},
        {0,0,0,1,-2}
    };
   
    vector<double> B
    {
        -1,
         0,
         0,
         0,
        -1
    };
   
    int n = 5;
    forward_eli(A, B);
    backward_eli(A, B);
    cout << setprecision(3);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << A[i][j]<<' ';
        }
        cout << '|' << B[i] << '\n';
    }
}