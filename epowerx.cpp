#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    double x;
    cout<<"Enter a value for x: ";
    cin>>x;
    
    double exact = exp(x);
    cout << "The value of e^" << x << " is: " << exact << "\n\n";
    
    vector<double> forward1, forward2, backward1, backward2, central1,central2;
    double calculate; 
    
    cout<<"\nFORWARD DIFFERENCE METHODS:\n";
    // forward 1
    cout<<"f'(x) = f(x+h) - f(x) / h\n";
    double h=0.1;
    for(int i=0;i<=9;i++)
    {
        h/=pow(2,i);
        calculate=(exp(x+h)-exp(x))/h;
        cout << "The value of e^" << x << " at (h=" << h << ") is: " << calculate << "\n";
        forward1.push_back(calculate);
    }
    
    // forward 2
    cout<<"\nf'(x) = -f(x + 2*h) + 4*f(x+h) - 3*f(x) / 2*h\n";
    h=0.1;
    for(int i=0;i<=9;i++)
    {
        h/=pow(2,i);
        calculate=((4*exp(x+h))-(3*exp(x))-(exp(x+2*h)))/(2*h);
        cout << "The value of e^" << x << " at (h=" << h << ") is: " << calculate << "\n";
        forward2.push_back(calculate);
    }
    cout<<"\n********************************\n";
    
    cout<<"\nBACKWARD DIFFERENCE METHODS:\n";
    // backward 1
    cout<<"\nf'(x) = f(x) - f(x-h) / h\n";
    h=0.1;
    for(int i=0;i<=9;i++)
    {
        h/=pow(2,i);
        calculate=(exp(x)-exp(x-h))/h;
        cout << "The value of e^" << x << " at (h=" << h << ") is: " << calculate << "\n";
        backward1.push_back(calculate);
    }
    
    // backward 2
    cout<<"\nf'(x) = f(x) - 4*f(x-h) + f(x - 2*h) / 2*h\n";
    h=0.1;
    for(int i=0;i<=9;i++)
    {
        h/=pow(2,i);
        calculate=((exp(x))-(4*exp(x-h))+(exp(x-2*h)))/(2*h);
        cout << "The value of e^" << x << " at (h=" << h << ") is: " << calculate << "\n";
        backward2.push_back(calculate);
    }
    cout<<"\n********************************\n";
    
    cout<<"\nCENTRAL DIFFERENCE METHODS:\n";
    // central 1
    cout<<"\nf'(x) = f(x+h) - f(x-h) / 2*h\n";
    h=0.1;
    for(int i=0;i<=9;i++)
    {
        h/=pow(2,i);
        calculate=(exp(x+h)-exp(x-h))/(2*h);
        cout << "The value of e^" << x << " at (h=" << h << ") is: " << calculate << "\n";
        central1.push_back(calculate);
    }
    
    // central 2
    cout<<"\nf'(x) = - f(x+2*h) + 8*f(x+h) - 8*f(x-h) + f(x - 2*h) / 12*h\n";
    h=0.1;
    for(int i=0;i<=9;i++)
    {
        h/=pow(2,i);
        calculate=((8*exp(x+h))-(exp(x+2*h))-(8*exp(x-h))+(exp(x-2*h)))/(12*h);
        cout << "The value of e^" << x << " at (h=" << h << ") is: " << calculate << "\n";
        central2.push_back(calculate);
    }
    cout<<"\n********************************\n";
    
    cout<<"\nABSOLUTE ERROR:\n";
    cout<<"\nAbsolute Error(Forward 1): "<<abs(exact-forward1[0]);
    cout<<"\nAbsolute Error(Forward 2): "<<abs(exact-forward2[0]);
    cout<<"\nAbsolute Error(Backward 1): "<<abs(exact-backward1[0]);
    cout<<"\nAbsolute Error(Backward 2): "<<abs(exact-backward2[0]);
    cout<<"\nAbsolute Error(Central 1): "<<abs(exact-central1[0]);
    cout<<"\nAbsolute Error(Central 2): "<<abs(exact-central2[0]);
    cout<<"\n********************************\n";

    cout<<"\nRELATIVE ERROR:\n";
    cout<<"\nRelative Error(Forward 1): "<<abs(exact-forward1[0])/x;
    cout<<"\nRelative Error(Forward 2): "<<abs(exact-forward2[0])/x;
    cout<<"\nRelative Error(Backward 1): "<<abs(exact-backward1[0])/x;
    cout<<"\nRelative Error(Backward 2): "<<abs(exact-backward2[0])/x;
    cout<<"\nRelative Error(Central 1): "<<abs(exact-central1[0])/x;
    cout<<"\nRelative Error(Central 2): "<<abs(exact-central2[0])/x;
    cout<<"\n********************************\n";
    
    return 0;
}