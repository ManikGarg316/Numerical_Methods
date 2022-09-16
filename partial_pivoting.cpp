#include<bits/stdc++.h>
using namespace std;

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

void Eliminate(vector<vector<double>> &A, vector<double> &S, vector<double> &B, double &tol, int &er)
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

int main()
{
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
    vector<double> X(n);
    int er = 0;
    double tol = 0.00000001;
    Gauss(A, B, X, tol, er);
    cout << "Values of X: ";
    for(int i=0;i<n;i++)
    {
        cout << X[i] << ' ';
    }
    cout << '\n';
}