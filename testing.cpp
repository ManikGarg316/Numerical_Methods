#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

// #define f(x) 3*x-cos(x)-1
// #define g(x) 3+sin(x)
// #define f(x) x*x*x-5*x-9
//g(x) is derivative of f(x)
// #define g(x) 3*x*x-5
// #define f(x) x*x-2*x+1
// #define g(x) 2*x-2
// #define e 1e-12

// void newtonRaphson(double x0){
//     // ofstream output("output_a.txt");
//     std::fstream output("output_a.txt", std::ios_base::out);
//     double gx0, fx0, fx1 = 1, x1;
//     int iterations = 0;

//     while(abs(fx1)>e){
//         gx0 = g(x0);
//         fx0 = f(x0);

//         if(gx0==0){
//             cout<<"Mathematical error! g(x) comes out to be zero!!"<<endl;
//             output<<"No root"<<endl;
//             output.close();
//             return;
//         }
//         output<<"x: "<<to_string(x0)<<" error: "<<to_string(abs(fx0/gx0))<<" f(x): "<<to_string(fx0);

//         x1=x0-fx0/gx0;
//         x0=x1;
//         fx1 = f(x1);
//         ++iterations;
//     }
//     cout<<x1<<endl;
//     output<<"Value of Root: "<<to_string(x1)<<endl;
//     output<<"Iterations required: "<<to_string(iterations)<<endl;

//     output.close();
// }
void printInoutput(){
    // std::fstream file("input.txt", std::ios_base::in);
    // std::fstream output("output_a.txt", std::ios_base::out);
    ofstream output("output_a.txt");
    output<<"shivam";
    output.close();
}
int main()
{
    // double x0; cin >> x0;
    // cout<<setprecision(6)<<fixed;
    // newtonRaphson(x0);
    printInoutput();
}