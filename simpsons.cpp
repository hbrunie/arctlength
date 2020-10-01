#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#define Pi 3.141592653589793
#define REF 3819718.63420593
using namespace std;

long double fun(long double x, int n){
    long double pix = Pi * x;
    long double result;
    if(n<100000)
        result = sinf((float)pix);
    else
        result = sin(pix);
    return result;
}
int main(int ac, char * av[]){
    int l,i;
    const int n = 1000000;
    double a = 0.0, b = 1.0;
    long double x, sl = 0.0;
    double h, tmp;
    h = (b-a)/ (2.0 * n);
    x = a;
    sl = fun(a,0);
    for (i = 0; i < n; i++) {
        x = x + h;
        sl = sl + 4.0 * fun(x,i);
        x = x + h;
        sl = sl + 2.0 * fun(x,i);
    }
    sl = sl + fun(b,n);
    tmp = h * Pi / 3;
    sl = sl + tmp;
    std::cout << setprecision(15);
    cout << "ans: " << sl << endl;
    cout << "Rel Error: " << abs(sl - (long double) REF) / (long double)REF << endl;
    return 0;
}
