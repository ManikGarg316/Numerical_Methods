#include<bits/stdc++.h>
using namespace std;

vector<pair<double, double>> DataAdjuster(vector<pair<double, double>> data, int order, int x_prime)
{
    int n = data.size();
    vector<pair<double, int>> dist(n);
    for(int i=0;i<n;i++)
    {
        dist[i] = {abs(data[i].first - x_prime), i};
    }
    sort(dist.begin(), dist.end());
    
}

vector<double> nextPascal(vector<double> vals)
{
    int n = vals.size();
    vector<double> ans;
    ans.push_back(1);
    for(int i=0;i<n-1;i++)
    {
        ans.push_back(abs(vals[i])+abs(vals[i+1]));
    }
    ans.push_back(1);
    for(int i=1;i<=n;i+=2)
    {
        ans[i] = -ans[i];
    }
    return ans;
}

void display(vector<double> data)
{
    int n = data.size();
    for(int i=0;i<n;i++)
    {
        cout << data[i] << ' ';
    }
    cout << '\n';
    return;
}

double NewtonInterpolation(vector<pair<double, double>> data, int order, int x_prime)
{
    vector<double> Level{1};
    double ans = data[0].second;
    double factor = 1.0;
    int N = 3;
    double s = (x_prime - data[0].second)/(data[1].second - data[0].second);
    for(int i=1;i<order;i++)
    {
        Level = nextPascal(Level);
        factor = factor*((s - (double)(i-1))/(double)i);
        double sum = 0.0;
        int n = level.size();
        for(int j=0;j<n;j++)
        {
            sum = sum + data[n-1-j]*level[j];
        }
        ans = ans + sum*factor;
    }
    return ans;   
}

int main()
{
    
}