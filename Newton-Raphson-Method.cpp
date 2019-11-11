#include <bits/stdc++.h>
using namespace std;

class NewtonRaphsonMethod{
    public:
        double x;

     public :

        double func(double x){
            return (x*x*x) - (2*x) - 5.0;
        }

        double derivedFunc(double x){
            return (3*x *x) - 2.0;
        }

        void initialGuess(){
            x = 0.0;
            cout << "For expression x^3 - 2x - 5, the initial guess is: " << endl;
            cout << "x =" << x << endl;
        }

        void getSolution(double e){

            double h = func(x)/derivedFunc(x);
            int i = 0;
            cout << "x" << i << " = " << x << endl;

            while(fabs(h) >= e){

                 h = func(x)/derivedFunc(x);
                 // x(i+1) = x(i) - f(x)/f'(x);
                 x = x - h;
                 cout << "x" << ++i << " = " << x << endl;
            }
            cout << "The solution is x = " << x << endl;
        }
};

int main(){
    NewtonRaphsonMethod n;
    n.initialGuess();
    n.getSolution(0.0001);
    return 0;
}
