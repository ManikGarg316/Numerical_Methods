#include<bits/stdc++.h>
using namespace std;
void Display(vector<pair<double, double>> data)
{
    int n = data.size();
    for(int i=0;i<n;i++)
    {
        cout << data[i].first << ' ';
    }
    cout << '\n';
    return;
}

vector<pair<double, double>> DataAdjuster(vector<pair<double, double>> data, int order, double x_prime)
{
    //Better to just put points manually
    sort(data.begin(), data.end());
    int n = data.size();
    vector<pair<double, double>> ans;
    double avg_ans = 0.0;
    bool found = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            double end = data[j].first;
            double dist = abs(data[j].first - data[i].first);
            vector<pair<double, double>> temp{data[i], data[j]};
            double avg_temp = data[i].first + data[j].first;
            // cout << dist << '\n';
            for(int k=j+1;k<n;k++)
            {
                // cout << abs(end - data[k].first) << '\n';
                if(abs(end - data[k].first) == dist)
                {
                    temp.push_back(data[k]);
                    end = data[k].first;
                    avg_temp += data[k].first;
                }
                if(temp.size() == order+1)
                {
                    avg_temp = avg_temp/(double)(order+1);
                    if(!found)
                    {
                        ans = temp;
                        avg_ans = avg_temp;
                        found = true;
                    }
                    else if(abs(avg_ans - x_prime) > abs(avg_temp - x_prime))
                    {
                        // cout << abs(temp[order].first - x_prime) << ' ' << abs(ans[order].first - x_prime) << '\n';
                        // cout << abs(temp[0].first - x_prime) << ' ' << abs(ans[0].first - x_prime) << '\n';
                        avg_ans = avg_temp;
                        ans = temp;
                    }
                    else if(abs(avg_ans - x_prime) == abs(avg_temp - x_prime) && (abs(temp[order].first - temp[0].first) < abs(ans[order].first - ans[0].first)))
                    {
                        avg_ans = avg_temp;
                        ans = temp;
                    }
                    Display(ans);
                    break;
                }
            }
        }
    }
    return ans;
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
    data = DataAdjuster(data, order, x_prime);
    Display(data);
    vector<double> Level{1};
    double ans = data[0].second;
    double factor = 1.0;
    int N = 3;
    double s = (x_prime - data[0].first)/(data[1].first - data[0].first);
    for(int i=1;i<=order;i++)
    {
        Level = nextPascal(Level);
        factor = factor*((s - (double)(i-1))/(double)i);
        double sum = 0.0;
        int n = Level.size();
        for(int j=0;j<n;j++)
        {
            sum = sum + data[n-1-j].second*Level[j];
        }
        ans = ans + sum*factor;
    }
    return ans;   
}

int main()
{
    int order_of_eqn = 3;
    double val = 523;
    vector<pair<double, double>> data_points
    {
        {250, 1.003},
        {300, 1.005},
        {350, 1.008},
        {400, 1.013},
        {450, 1.020},
        {500, 1.029},
        {550, 1.040},
        {600, 1.051},
        {650, 1.063},
        {700, 1.075},
        {750, 1.087},
        {800, 1.099},
        {900, 1.121},
        {1000, 1.142}
    };
    cout << NewtonInterpolation(data_points, order_of_eqn, val);
}