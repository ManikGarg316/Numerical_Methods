#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

vector<vector<double>> Jacobian(vector<double> Init)
{
    double x = Init[0], y = Init[1], z = Init[2];
    vector<vector<double>> jac
    {
        {1,1,1},
        {y+z, x+z, x+y},
        {y*y + ((double)2)*x*z - y*z, z*z + ((double)2)*x*y - x*z, x*x + ((double)2)*y*z - x*y}
    };
    return jac;
}

vector<double> Bcal(vector<double> Init)
{
    double x = Init[0], y = Init[1], z = Init[2];
    vector<double> B
    {
        (double)-1*(x+y+z - (double)3),
        (double)-1*(x*y + y*z + z*x - (double)3),
        (double)-1*(x*y*y + y*z*z + z*x*x - x*y*z - (double)2)
    };
    return B;
}

void Pivot(vector<vector<double>>&A, vector<double>&B, vector<double> &S, int k)
{
    int n = A.size();
    int p = k;
    double big = abs(A[k][k]/S[k]);
    for(int ii=k+1;ii<n;ii++)
    {
        double dummy = abs(A[ii][k]/S[ii]);
        if(dummy>big)
        {
            big = dummy;
            p=ii;
        }
    }
    if(p!=k)
    {
        double dummy;
        for(int jj=k;jj<n;jj++)
        {
            dummy = A[p][jj];
            A[p][jj]=A[k][jj];
            A[k][jj]=dummy;
        }
        dummy = B[p];
        B[p] = B[k];
        B[k]=dummy;
        dummy = S[p];
        S[p]=S[k];
        S[k]=dummy;
    }
    return;
}

void Substitute(vector<vector<double>>&A, vector<double> &B, vector<double> &X)
{
    int n = A.size();
    X[n-1]=B[n-1]/A[n-1][n-1];
    for(int i=n-2;i>=0;i--){
        double sum=0;
        for(int j=i+1;j<n;j++)
        {
            sum = sum + A[i][j]*X[j];
        }
        X[i] = (B[i]-sum)/A[i][i];
    }
    return;
}

void Eliminate(vector<vector<double>> &A, vector<double> &S, vector<double> &B, double tol, int &er)
{
    int n = A.size();
    for(int k=0;k<n-1;k++)
    {
        Pivot(A, B, S, k);
        if(abs(A[k][k]/S[k]) < tol)
        {
            er = -1;
            break;
        }
        for(int i=k+1;i<n;i++)
        {
            double fact=A[i][k]/A[k][k];
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
    if(abs(A[n-1][n-1]/S[n]) < tol)
    {
        er = -1;
    }
    return;
}

void Gauss(vector<vector<double>> &A, vector<double> &B, vector<double> &X, double tol, int& er)
{
    int n = A.size();
    vector<double> S(n);
    for(int i=0;i<n;i++)
    {
        S[i] = abs(A[i][0]);
        for(int j=1;j<n;j++)
        {
            if(abs(A[i][j]) > S[i])
            {
                S[i] = abs(A[i][j]);
            }
        }
    }
    Eliminate(A, S, B, tol, er);
    if(er != -1)
    {
        Substitute(A, B, X);
    }
    return;
}

void coupledeqns(vector<double> &Guess, double error)
{
    int n = Guess.size();
    while(1)
    {
        vector<double> vals(n);
        vector<vector<double>> Jacob = Jacobian(Guess);
        vector<double> B = Bcal(Guess);
        double tol = 0.0000001;
        int er = 0;
        bool flag = true;
        for(int i=0;i<n;i++)
        {
            if(abs(B[i]) > error)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            return;
        }
        Gauss(Jacob, B, vals, tol, er);
        // for(int i=0;i<n;i++)
        // {
        // cout << Guess[i] << ' ';
        // }
        // cout << '\n';
        for(int i=0;i<n;i++)
        {
            Guess[i] = Guess[i] + vals[i];
        }
    }
    return;
}
int main()
{
    double epsilon = 0.0000001;
    vector<double> Initial_Guess{0,2,3};
    int n = Initial_Guess.size();
    coupledeqns(Initial_Guess, epsilon);
    return 0;
}
