#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

double f(double x)
{
    return pow(x, 4.0) - pow(x, 3.0) + pow(x, 2.0) - x + (double)1;
    // double temp = 1.0;
    // double ans = 1.0;
    // for(int i=0;i<4;i++)
    // {
    //     temp = temp*(-x);
    //     ans += temp;
    // }
    // return ans;
}

vector<pair<double, double>> Points_Generator(double h, double a, double b)
{
    ofstream OUTPUT("./output.txt");
    vector<pair<double, double>> ans;
    while(a<=b)
    {
        ans.push_back({a, f(a)});
        a += h;
    }
    OUTPUT.close();
    return ans;
}

double exact(double x)
{
    ofstream OUTPUT("./output.txt");
    OUTPUT.close();
    return ((double)4)*pow(x, 3.0) - ((double)3)*pow(x, 2.0) + ((double)2)*x - ((double)1);
}

// vector<int> nextPascal(vector<int> vals)
// {
//     int n = vals.size();
//     vector<int> ans;
//     ans.push_back(1);
//     for(int i=0;i<n-1;i++)
//     {
//         ans.push_back(abs(vals[i])+abs(vals[i+1]));
//     }
//     ans.push_back(1);
//     for(int i=1;i<=n;i+=2)
//     {
//         ans[i] = -ans[i];
//     }
//     return ans;
// }

// double NewtonForwardScheme_FirstOrder(double x0, double h, int order_of_accuracy)
// {
//     double ans = 0.0;
//     vector<double> y = Points_Generator(x0, h, order_of_accuracy+1);
   
//     vector<int> Level{1};
//     for(int i=0;i<order_of_accuracy;i++)
//     {
//         Level = nextPascal(Level);
//         double temp = 0.0;
//         for(int j=0;j<Level.size();j++)
//         {
//             temp = temp + ((double)Level[j])*y[j];
//         }
//         temp = temp/(double)(i+1);
//         if((i+1)%2 == 0)
//         {
//             ans -= temp;
//         }
//         else
//         {
//             ans += temp;
//         }
//     }
//     return ans/h;
// }

double Trapezoidal(vector<pair<double, double>> data, double h)
{
    ofstream OUTPUT("./output.txt");
    int n = data.size();
    double ans = 0.0;
    for(int i=1;i<n-1;i++)
    {
        ans = ans + ((double)2)*data[i].second;
    }
    ans = ans + data[0].second + data[n-1].second;
    OUTPUT.close();
    return (ans*h)/((double)2);
}

double SimpsonOneThird(vector<pair<double, double>> data, double h)
{
    ofstream OUTPUT("./output.txt");
    int n = data.size();
    double ans = 0.0;
    if(n<3)
    {
        cout << "Cannot do it! Not enough points!";
        exit(0);
    }
    for(int i=0;i<n-2;i+=2)
    {
        ans = ans + data[i].second + ((double)4)*data[i+1].second + data[i+2].second;
    }
    if(n%2 == 0)
    {
        ans = ans/((double)3) + (data[n-2].second + data[n-1].second)/((double)2);
    }
    else
    {
        ans = ans/((double)3);
    }
    OUTPUT.close();
    return ans*h;
}

double SimpsonThreeEighth(vector<pair<double, double>> data, double h)
{
    ofstream OUTPUT("./output.txt");
    int n = data.size();
    double ans = 0.0;
    if(n<4)
    {
        cout << "Cannot do it! Not enough points!";
        exit(0);
    }
    for(int i=0;i<n-3;i+=3)
    {
        ans = ans + data[i].second + ((double)3)*data[i+1].second + ((double)3)*data[i+2].second + data[i+3].second;
    }
    if(n%3 == 2)
    {
        ans = (ans*(double)3)/((double)8) + (data[n-2].second + data[n-1].second)/((double)2);
    }
    else if(n%3 == 0)
    {
        ans = (ans*(double)3)/((double)8) + (data[n-3].second + ((double)4)*data[n-2].second + data[n-1].second)/((double)3);
    }
    else
    {
        ans = (ans*(double)3)/((double)8);
    }
    OUTPUT.close();
    return ans*h;
}

int main() {
    // cout << exact(5.0) << '\n';
    // cout << NewtonForwardScheme_FirstOrder(5.0, 0.0001, 100);
    vector<pair<double, double>> data_points
    {
        {0,-1},
        {1,2},
        {2,23},
        {3,86},
        {4,215},
        {5,434},
        {6,767},
        {7,1238},
        {8,1871},
        {9,2690},
        {10,3719}
    };
    // cout << Trapezoidal(data_points) << '\n';
    cout << SimpsonOneThird(data_points, 1) << '\n';
}