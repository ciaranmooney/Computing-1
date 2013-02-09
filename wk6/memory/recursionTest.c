//
//
//

#include <stdio.h>
#include <math.h>

int main (int argc, const char* argv[]){
    double x;
    int y;
    //3.40282e+38
    //1.17549e-38
    //1.79769e+308
    // 2.22507e-308
    double z;
    double a;
    z = pow(10,308);
    a = 0.00000000000000222508; 
    x = a/z;
    y = 0;
    while (y < 10) {
        a = a / 10;
        x = a/z;
        printf("%.350f\n",  x);
        y = y + 1;
    }
    return 1;
}
