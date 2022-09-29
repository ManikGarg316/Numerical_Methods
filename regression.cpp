#include <bits/stdc++.h>

using namespace std;
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
    vector<vector<double>> matA = regA(data, order_of_eqn);
    vector<double> vecB = regB(data, order_of_eqn);
    int n = data.size();
    display(matA, vecB, order_of_eqn);
   
    //partial_pivoting
}
