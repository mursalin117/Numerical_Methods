#include <bits/stdc++.h>
using namespace std;

class Bisection{
    public :
        double a, b;
        int i = 0;

    public :
        double getFunction(double x){
            return (x * x * x) - x + 1.0;
        }

        void initialGuess(){
            a = 0.0;
            while(getFunction(a) > 0.0){
                a -= 0.5;
            }
            b = 0.0;
            while(getFunction(b) < 0.0){
                b += 0.5;
            }
            cout << "For expression x^3 - x + 1, the initial guess is: " << endl;
            cout << "a =" << a << "  b = " << b << endl;
        }

        void getSolution()
        {
            double c = (a + b)/ 2.0;
            cout << c << endl;
            while(fabs(getFunction(c)) >= 0.0001){
                cout << "c" << ++i << " = " << c << endl;
                if((getFunction(c) * getFunction(a)) > 0.0) a = c;
                else if((getFunction(c) * getFunction(a)) < 0.0) b = c;
                else break;
                c = (a + b)/ 2.0;
            }
            cout << "The solution is " << c << endl;
        }
};

int main()
{
    Bisection b1;
    b1.initialGuess();
    b1.getSolution(); 
    return 0;
}
