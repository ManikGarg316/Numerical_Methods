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

double QuadraticSpline(vector<pair<double, double>> data, double x_prime)
{
    ofstream OUTPUT("./output.txt");
    int itr=1;
    int n = data.size();
    for(;itr<n;itr++)
    {
        if(x_prime < data[itr].first && data[itr-1].first < x_prime)
        {
            break;
        }
    }
    itr--;
    vector<double> d(n, 0.0);
    for(int i=0;i<n-1;i++)
    {
        d[i+1] = (((double)2)*(data[i+1].second - data[i].second))/(data[i+1].first - data[i].first);
        d[i+1] = d[i+1] - d[i];
    }
    double a = pow(x_prime - data[itr].first, 2.0);
    double ans = ((d[itr+1] - d[itr])*a)/(2*(data[itr+1].first - data[itr].first));
    ans = ans + (d[itr]*(x_prime - data[itr].first));
    ans = ans + data[itr].second;
    OUTPUT.close();
    return ans;
    // int n = data.size();
    // 
    // cout << data[itr-1].first << ' ' << data[itr-1].second << '\n';
    // cout << data[itr].first << ' ' << data[itr].second << '\n';
    // vector<vector<double>> A(n, vector<double>(n));
    // vector<double> B(n);
    // for(int i=1;i<n-1;i++)
    // {
    //     A[i][i-1] = data[i].first - data[i-1].first;
    //     A[i][i] = data[i+1].first - data[i-1].first;
    //     A[i][i+1] = data[i+1].first - data[i].first;
    //     B[i] = (data[i+1].second - data[i-1].second);
    // }
    // A.pop_back();
    // B.pop_back();
    // A.erase(A.begin());
    // B.erase(B.begin());
    // for(int i=0;i<A.size();i++)
    // {
    //     A[i].erase(A[i].begin());
    //     A[i].pop_back();
    // }
    // vector<double> X(n-2);
    // int er = 0;
    // Gauss(A, B, X, 0.000001, er);
    // X.push_back(1);
    // X.insert(X.begin(), 23);
    // itr--;
    // double a = pow((x_prime - data[itr].first), 2.0);
    // double b = pow((x_prime - data[itr+1].first), 2.0);
    // double ans = (X[itr+1]*a)/(2*(data[itr+1].first - data[itr].first));
    // ans = ans + (X[itr]*b)/(2*(data[itr].first - data[itr+1].first));
    // ans += (data[itr].second + data[itr+1].second)/4;
    // ans = ans - ((data[itr+1].first - data[itr].first)*(X[itr+1] - X[itr]))/4;
    // 
    // return ans;
}

double CubicSpline(vector<pair<double, double>> data, double x_prime)
{
    int n = data.size();
    ofstream OUTPUT("./output.txt");
    int itr=1;
    for(;itr<n;itr++)
    {
        if(x_prime < data[itr].first && data[itr-1].first <= x_prime)
        {
            break;
        }
    }
    // cout << data[itr-1].first << ' ' << data[itr-1].second << '\n';
    // cout << data[itr].first << ' ' << data[itr].second << '\n';
    vector<vector<double>> A(n, vector<double>(n));
    vector<double> B(n);
    for(int i=1;i<n-1;i++)
    {
        A[i][i-1] = data[i-1].first - data[i].first;
        A[i][i] = ((double)2)*(data[i-1].first - data[i+1].first);
        A[i][i+1] = data[i].first - data[i+1].first;
        B[i] = ((double)6)*((data[i-1].second - data[i].second)/(data[i-1].first - data[i].first) - (data[i].second - data[i+1].second)/(data[i].first - data[i+1].first));
    }
    A.pop_back();
    B.pop_back();
    A.erase(A.begin());
    B.erase(B.begin());
    for(int i=0;i<A.size();i++)
    {
        A[i].erase(A[i].begin());
        A[i].pop_back();
    }
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            cout << A[i][j] << ' ';
        }
        cout << " | " << B[i] << '\n';
    }
    cout << "\n\n";
    vector<double> X(n-2);
    int er = 0;
    Gauss(A, B, X, 0.00000001, er);
    X.push_back(0);
    X.insert(X.begin(), 0);
    // cout << X.size() << '\n';
    for(int i=0;i<n;i++)
    {
        cout << X[i] << ' ';
    }
    cout << '\n';
    itr--;
    double a = pow(x_prime - data[itr+1].first, 3.0);
    double b = pow(x_prime - data[itr].first, 3.0);
    double ans = (X[itr]/6)*((a/(data[itr].first - data[itr+1].first)) - (x_prime - data[itr+1].first)*(data[itr].first - data[itr+1].first));
    ans = ans - (X[itr+1]/6)*((b/(data[itr].first - data[itr+1].first) - (x_prime - data[itr].first)*(data[itr].first - data[itr+1].first)));
    ans += (data[itr].second*(x_prime - data[itr+1].first) - data[itr+1].second*(x_prime - data[itr].first))/(data[itr].first - data[itr+1].first);
    OUTPUT.close();
    return ans;
}

double LinearSpline(vector<pair<double, double>> data, double x_prime)
{   
    int n = data.size();
    ofstream OUTPUT("./output.txt");
    int itr=1;
    for(;itr<n;itr++)
    {
        if(x_prime < data[itr].first && data[itr-1].first < x_prime)
        {
            break;
        }
    }
    double b = (data[itr-1].second - data[itr].second)/(data[itr-1].first - data[itr].first);
    double a = data[itr-1].second - b*data[itr-1].first;
    OUTPUT.close();
    return a+b*x_prime;
}

int main()
{
    double val = 20;
    vector<pair<double, double>> data_points
    {
        {48,83},
        {28,62},
        {63, 93},
        {64, 70},
        {5, 35},
        {4, 84},
        {16, 60},
        {10, 64},
        {65, 93},
        {17, 83},
    };
    sort(data_points.begin(), data_points.end());
    for(int i=0;i<10;i++)
    {
        cout << data_points[i].first << " " << data_points[i].second << '\n';
    }
    if(val > data_points[data_points.size()-1].first || val < data_points[0].first)
    {
        cout << "Value out of range. Can't extrapolate\n";
        exit(0);
    }
    cout << QuadraticSpline(data_points, 60.0);
}