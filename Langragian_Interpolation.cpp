#include <bits/stdc++.h>
using namespace std;

vector<double> finding_coeff(vector<pair<double, double>> vals)
{
    int n = vals.size();
    vector<double> Coeffs(n);
    for(int i=0;i<n;i++)
    {
        double x = vals[i].second;
        for(int j=0;j<n;j++)
        {
            if(i != j)
            {
                x = x/(vals[i].first - vals[j].first);
            }
        }
        Coeffs[i] = x;
    }
    return Coeffs;
}

vector<pair<double, double>> proper_set(vector<pair<double, double>> vals, int x_prime, int eqn_order)
{
    int n = vals.size();
    if(eqn_order+1 == n)
    {
        return vals;
    }
    if(eqn_order+1 > n)
    {
        cout << "ERROR: Insufficient data points. Get more data points or decrease the order of equation\n";
        exit(0);
        return vals;
    }
    // sort(vals.begin(), vals.end());
    vector<pair<double, int>> dist(n);
    for(int i=0;i<n;i++)
    {
        dist[i] = {abs(vals[i].first - x_prime), i};
    }
    sort(dist.begin(), dist.end());
   
    vector<pair<double, double>> ans(eqn_order+1);
    for(int i=0;i<eqn_order+1;i++)
    {
        ans[i] = vals[dist[i].second];
    }
    return ans;
}

double LangragianInterpolation(vector<pair<double, double>> DATA, int x_prime, int order)
{
    vector<pair<double, double>> DATA_REQUIRED = proper_set(DATA, x_prime, order);
    // for(int i=0;i<order+1;i++)
    // {
    //     cout << DATA_REQUIRED[i].first << ' ' << DATA_REQUIRED[i].second << '\n';
    // }
    vector<double> coeff = finding_coeff(DATA_REQUIRED);
    int n = DATA_REQUIRED.size();
    double ans = 0;
    for(int i=0;i<n;i++)
    {
        double x = coeff[i];
        for(int j=0;j<n;j++)
        {
            if(i != j)
            {
                x = x*(x_prime - DATA_REQUIRED[j].first);
            }
        }
        ans = ans+x;
    }
    return ans;
}

int main()
{
    vector<pair<double, double>> DATA_POINTS
    {
        {250, 1.003},
        {300, 1.005},
        {350, 1.008}
        // {400, 1.013},
        // {450, 1.020},
        // {500, 1.029},
        // {550, 1.040},
        // {600, 1.051},
        // {650, 1.063},
        // {700, 1.075},
        // {750, 1.087},
        // {800, 1.099},
        // {900, 1.121},
        // {1000, 1.142}
    };
    int order_of_eqn = 2;
    double val_find = 273;
    cout << LangragianInterpolation(DATA_POINTS, val_find, order_of_eqn);
}
