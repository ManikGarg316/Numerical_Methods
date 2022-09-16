#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// double error = 0.00000001;
void forward_eli(vector<vector<double>> &A, vector<double> &B)
{
    int n = A.size();
    for(int k=0;k<n-1;k++)
    {
        for(int i=k+1;i<n;i++)
        {
            double fact = A[i][k]/A[k][k];
            A[i][k] = (double)0;
            for(int j=k+1;j<n;j++)
            {
                A[i][j] = A[i][j] - fact*A[k][j];
                // if(A[j][k] < error)
                // {
                //     A[j][k] = 0;
                // }
            }
            B[i] = B[i] - fact*B[k];
        }
    }
    return;
}

vector<double> back_sub(vector<vector<double>> &A, vector<double> &B)
{
    int n = A.size();
    vector<double> X(n);
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
    return X;
}

int main()
{
    double val = pow(2, -10);
    vector<vector<double>> A
    {
        {0.0000000000000001, 2},
        {1, -1}
    };
   
    vector<double> B
    {
        4,
        1
    };
   
    int n = A.size();
    forward_eli(A, B);
    vector<double> ANS = back_sub(A, B);
    cout << setprecision(3);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << A[i][j]<<' ';
        }
        cout << '|' << B[i] << '\n';
    }
    cout<<'\n';
    cout<<"Values of X:\n";
    for(int i=0;i<ANS.size();i++)
    {
        cout << ANS[i] << ' ';
    }
    cout<<'\n';
}