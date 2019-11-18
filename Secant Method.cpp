#include <bits/stdc++.h>
using namespace std;

class secantMethod{
    public:
        double x0, x1;
        int i = 2;

     public :
        double f(double x){
            return (x * x * x) - (2*x) - 5.0;
        }

        void initialGuess(){
            x0 = 0.0;
            while(f(x0) > 0.0){
                x0 -= 0.5;
            }
            x1 = 0.0;
            while(f(x1) < 0.0){
                x1 += 0.5;
            }
            cout << "For expression x^3 - 2x - 5, the initial guess is: " << endl;
            cout << "x0 = " << x0 << endl;
            cout << "x1 = " << x1 << endl;
        }

        void getSolution(double e){
            // x2 = x1 - ((x1 - x0)/(f(x1)-f(x0)))*f(x1)
            double x = x1 - ((x1 - x0)/(f(x1)-f(x0)))*f(x1);
            cout << "x" << i << " = " << x << endl;

            while(fabs(f(x)) >= e){

                x = x1 - ((x1 - x0)/(f(x1)-f(x0)))*f(x1);
                cout << "x" << ++i << " = " << x << endl;
                x0= x1;
                x1 = x;
            }
            cout << "The solution is x = " << x << endl;
        }
};

int main(){
    secantMethod s;
    s.initialGuess();
    s.getSolution(0.0001);
    return 0;
}

