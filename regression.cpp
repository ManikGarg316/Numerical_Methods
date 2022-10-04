#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
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

vector<double> regB(vector<pair<double, double>> data_points, int order)
{
    int n = data_points.size();
    vector<double> B(order+1, 0.0);
    vector<double> vals_x(n, 1.0);
    for(int i=0;i<=order;i++)
    {
        for(int j=0;j<n;j++)
        {
            B[i] += vals_x[j]*data_points[j].second;
            vals_x[j] = vals_x[j]*data_points[j].first;
        }
    }
    return B;
}

vector<vector<double>> regA(vector<pair<double, double>> data_points, int order)
{
    int n = data_points.size();
    vector<vector<double>> A(order+1, vector<double>(order+1));
    vector<double> vals_x(n, 1.0);
   
    for(int j=0;j<=order;j++)
    {
        int itr_i = 0;
        int itr_j = j;
        double sum = 0.0;
        for(int k=0;k<n;k++)
        {
            sum += vals_x[k];
            vals_x[k] = vals_x[k]*data_points[k].first;
        }
        while(itr_i <= order && itr_j >= 0)
        {
            A[itr_i][itr_j] = sum;
            itr_i++;
            itr_j--;
        }
    }
    for(int i=1;i<=order;i++)
    {
        int itr_i = i;
        int itr_j = order;
        double sum = 0.0;
        for(int k=0;k<n;k++)
        {
            sum += vals_x[k];
            vals_x[k] = vals_x[k]*data_points[k].first;
        }
        while(itr_i <= order && itr_j >= 0)
        {
            A[itr_i][itr_j] = sum;
            itr_i++;
            itr_j--;
        }
    }
    return A;
}

void display(vector<vector<double>> A, vector<double> B, int order)
{
    for(int i=0;i<=order;i++)
    {
        for(int j=0;j<=order;j++)
        {
            cout << A[i][j] << ' ';
        }
        cout << " |  " << B[i] << '\n';
    }
    cout << "\n\n";
    return;
}

double regression(vector<pair<double, double>> data, double x_prime, int order)
{
    ofstream OUTPUT("./output.txt");
    int n = data.size();
    vector<vector<double>> matA = regA(data, order);
    vector<double> vecB = regB(data, order);
    vector<double> X(order+1);
    int er = 0;
    Gauss(matA, vecB, X, 0.000001, er);
    double ans = 0;
    for(int i=0;i<X.size();i++)
    {
        ans = ans + pow(x_prime, i)*X[i];
    }
    OUTPUT.close();
    return ans;
}

int main()
{
    vector<pair<double, double>> data
    {
        {0,0},
        {2,0},
        {6,0},
        {8,0},
        {10,0}
    };
    int order_of_eqn = 1;
    //a0 + a1*x
    double val = 0.0;
    // display(matA, vecB, order_of_eqn);
    double ans = regression(data, val, order_of_eqn);
    //partial_pivoting
}
