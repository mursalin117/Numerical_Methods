#include <bits/stdc++.h>
using namespace std;

class falsePosition{
    public:
        double x0, x1;

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
            cout << "x0 =" << x0 << "  x1 = " << x1 << endl;
        }

        void getSolution(double e){
            // x = [x0*f(x1) – x1*f(x0)] / (f(x1) – f(x0))
            double x = ((x0 * f(x1)) - (x1 * f(x0))) / (f(x1) - f(x0));
            cout << "x = " << x << endl;

            while(fabs(f(x)) >= e){
                 cout << "x" << " = " << x << endl;

                if((f(x) * f(x1)) > 0.0)
                    x1 = x;
                else if((f(x) * f(x1)) < 0.0)
                    x0 = x;
                else break;

                x = ((x0 * f(x1)) - (x1 * f(x0))) / (f(x1) - f(x0));
            }
            cout << "The solution is x = " << x << endl;
        }
};

int main(){
    falsePosition f;
    f.initialGuess();
    f.getSolution(0.0001);
    return 0;
}
