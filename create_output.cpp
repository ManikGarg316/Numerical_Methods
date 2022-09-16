#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;
void create_output(vector<double> X)
{
    ofstream OUTPUT("./output.txt");
    bool flag = false;
    if(X.size() > 0)
    {
        OUTPUT << to_string(X[0]);
        for(int i=1;i<X.size();i++)
        {
            OUTPUT << "," << to_string(X[i]);
        }
        flag = true;
    }
    OUTPUT.close();
    if(!flag)
    {
        cout << "Vector was empty!\n";
    }
    return; 
}
int main()
{
    vector<double> A;
    create_output(A);
    return 0;
}