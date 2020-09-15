#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double fun(long double x){
    int k, n=5;
    double t1; // TUNED
    float d1 = 1.0L; // TUNED
    //long double t1;
    //long double d1 = 1.0L;
    t1 = x;
    for(k=1; k<= n; k++){
        d1 = 2.0 * d1;
        t1 = t1 + sin (d1*x) / d1;
    }
    return t1;
}

long double reffun(long double x){
    int k, n=5;
    //double t1; // TUNED
    //float d1 = 1.0L; // TUNED
    long double t1;
    long double d1 = 1.0L;
    t1 = x;
    for(k=1; k<= n; k++){
        d1 = 2.0 * d1;
        t1 = t1 + sin (d1*x) / d1;
    }
    return t1;
}

long double refarclength(int n){
    int i;
    long double h, t1, t2, dppi;
    //double h, t1, t2, dppi; // TUNED
    long double s1 = 0.;

    t1 = -1.0;
    dppi = acos(t1);
    s1 = 0.0;
    t1 = 0.0;
    h = dppi / n;

    for(i=1 ; i<= n ; i++) {
        t2 = reffun(i*h);
        s1 = s1 + sqrt(h*h + (t2 - t1)*(t2 - t1));
        t1 = t2;
    }
    return s1;
}

int main(int argc, char **argv) {
    for (int n = 1; n < 1000011 ; n+=10){
    int i;
    if(argc>1)
        n = atoi(argv[1]);
    //long double h, t1, t2, dppi;
    double h, t1, t2, dppi; // TUNED
    long double s1=0.;

    t1 = -1.0;
    dppi = acos(t1);
    s1 = 0.0;
    t1 = 0.0;
    h = dppi / n;

    for(i=1 ; i<= n ; i++) {
        t2 = fun(i*h);
        s1 = s1 + sqrt(h*h + (t2 - t1)*(t2 - t1));
        t1 = t2;
    }
    long double lds1 = s1;
    long double rs1 = refarclength(n);
    printf("Number iterations: %d\n",n);
    printf("%.15llf, %.15llf\n",lds1,rs1);
    printf("relative error: %.15llf\n",fabs(lds1-rs1) / rs1);
}
    return 0;
}
