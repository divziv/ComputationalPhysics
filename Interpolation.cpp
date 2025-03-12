#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{
    vector<float> x;
    vector<float> x_mid;
    vector<float> y;
    vector<float> g;
    float f;
    for(float i = 0.1; i <= 5; i += 0.1)
    {
        x.push_back(i);
    }
    
    for(int i = 0; i < x.size() - 1; i++)
    {
        x_mid.push_back((x[i] + x[i + 1]) / 2);
    }
    
    for(int i = 0; i < x.size(); i++)
    {
        f = pow(sin(x[i]),2) / pow(x[i],2);
        y.push_back(f);
    }
    
    for(int i = 0; i < x.size() - 1; ++i)
    {
        f = ((y[i] * (x_mid[i] - x[i + 1])) / (x[i] - x[i + 1])) - ((y[i + 1]*(x_mid[i] - x[i])) / (x[i] - x[i + 1]));
        g.push_back(f);
    }
    
    /*TEST RUN
    cout << "x and y: \n";
    for(int i = 0; i < 10; i++)
    {
        cout<< "x = " << x[i] << " y = " << y[i] << "\n";
    }
    
    cout << "\nx mid and g: \n";
    
    for(int i = 0; i < 10; i++)
    {
        cout<< "x_mid = " << x_mid[i] << " g = " << g[i] << "\n";
    }
    */
    
    
    cout << "x and y: \n(";
    for(int i = 0; i < x.size(); i++)
    {
        if(i != x.size() - 1)
            cout<< "(" << x[i] << "," << y[i] << "),";
        else
            cout<< "(" << x[i] << "," << y[i] << ")";
    }
    cout<<")\n";
    
    cout<<"\nFIRST ORDER:\n";
    
    cout << "\nx mid and g: \n";
    
    for(int i = 0; i < x_mid.size(); i++)
    {
        if(i != x_mid.size() - 1)
            cout<< "(" << x_mid[i] << "," << g[i] << "),";
        else
            cout<< "(" << x_mid[i] << "," << g[i] << ")";   
    }
    cout<<")\n";
    
    g.clear();
    for(int i = 0; i < x.size() - 2; ++i)
    {
        f = ((y[i] * (x_mid[i] - x[i + 1]) * (x_mid[i] - x[i + 2])) / ((x[i] - x[i + 1]) * (x[i] - x[i + 2]))) + ((y[i + 1]*(x_mid[i] - x[i])*(x_mid[i] - x[i+2])) / ((x[i+1] - x[i])*(x[i+1]-x[i+2]))) + ((y[i]*(x_mid[i]-x[i])*(x_mid[i]-x[i+1])) / ((x[i+2]-x[i])*(x[i+2]-x[i+1])));
        g.push_back(f);
    }
    
    cout<<"\nSECOND ORDER:\n";
    
    cout << "\nx mid and g: \n";
    
    for(int i = 0; i < x_mid.size(); i++)
    {
        if(i != x_mid.size() - 1)
            cout<< "(" << x_mid[i] << "," << g[i] << "),";
        else
            cout<< "(" << x_mid[i] << "," << g[i] << ")";   
    }
    cout<<")\n";


    return 0;
}