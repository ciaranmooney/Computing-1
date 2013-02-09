// Ciarán Mooney
// 31/12/12 (British Format)
// Code functions as writen by J. Saknussman, but has been tidied.

/*
* Julian Saknussemm
*
* Given Three points of a triangle, and another arbitrary point this program determines if that point lies inside
* the triangle.
*
* This is determined by satisfying the following rule:
* A point P(x,y) is inside triangle A(x0,y0), B(x1,y1), C(x2,y2)
* if
* P is on the same side of the line AB as C
* P is on the same side of the line BC as A
* and
* P is on the same side of the line AC as B
*
* A special case exits for a vertical line (inf gradient) when testing the side of the line
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NO_ERROR 0
#define ERROR    1

#define TRUE    1
#define FALSE   0

#define UNDER   -1
#define ON_LINE  0
#define ABOVE    1
 
int tests (); 
int vertPosition (double px, double py, double m, double b);
int sameSide (double px, double py, double m, double b, double lx,
               double ly);

int triangleTest (double x0, double y0, double x1, double y1, double x2, 
                  double y2, double px, double py); 

int main (int argc, char* argv[]) {
    tests();
    
    double x0,x1,x2;
    double y0,y1,y2;
    double px, py;
    int errorCode;
    int error;
    int inTriangle;

    errorCode = NO_ERROR;
    error = NO_ERROR;

    // get input
    printf("Triangle Vertex A (x,y): "); 
    errorCode += scanf("%lf,%lf", &x0,&y0);
    printf("Triangle Vertex B (x,y): "); 
    errorCode += scanf("%lf,%lf", &x1,&y1);
    printf("Triangle Vertex C (x,y): "); 
    errorCode += scanf("%lf,%lf", &x2,&y2);
    printf("Test Point (x,y): "); 
    errorCode += scanf("%lf,%lf", &px,&py);
 
    // print error
    if( errorCode != 8 ) {
        printf("\nSorry, but your inputted data seems to be incorrect. " 
               "Error: %d\n", errorCode);
        error = ERROR;
    }

    if (error != ERROR) { 
        inTriangle = triangleTest(x0,y0,x1,y1,x2,y2,px,py);

        if (inTriangle == TRUE) {
            printf("Point (%.2lf,%.2lf) is inside the Triangle\n.", px,py);
        }
    
        if (inTriangle == FALSE) {
            printf("Point (%.2lf,%.2lf) is outside the Triangle\n.", px,py);
        }
    }
    
    return error;
}

int tests () {
//  vertPosition (px, py, m, b);
    assert (vertPosition (2.0, 1.0, 1.0, 0.0 ) ==  UNDER);
    assert (vertPosition (2.0, 2.0, 1.0, 0.0 ) ==  ON_LINE);
    assert (vertPosition (2.0, 3.0, 1.0, 0.0 ) ==  ABOVE);

    assert (vertPosition (2.0, 1.0, -1.0, 4.0 ) ==  UNDER);
    assert (vertPosition (2.0, 2.0, -1.0, 4.0 ) ==  ON_LINE);
    assert (vertPosition (2.0, 3.0, -1.0, 4.0 ) ==  ABOVE);
  
    assert (vertPosition (-2.0, -2.0, 1.0, 2.0 ) ==  UNDER);
    assert (vertPosition (-2.0,  0.0, 1.0, 2.0 ) ==  ON_LINE);
    assert (vertPosition (-2.0,  2.0, 1.0, 2.0 ) ==  ABOVE);

    assert (vertPosition (0.0, 1.0, 0.0, 0.0 ) ==  ABOVE);
    assert (vertPosition (0.0, 0.0, 0.0, 0.0 ) ==  ON_LINE);
    assert (vertPosition (0.0, -1.0, 0.0, 0.0 ) ==  UNDER);
    
//  bothAbove (test1 (px, py, m, b, lx, ly));
    assert (sameSide (1.0, 4.0, 1.0, 2.0, 3.0, 6.0) == TRUE);
    assert (sameSide (1.0, 4.0, 1.0, 2.0, 3.0, 2.0) == FALSE);
    assert (sameSide (1.0, 4.0, 1.0, 2.0, 1.0, 1.0) == FALSE);
    assert (sameSide (1.0, 1.0, 1.0, 1.0, 3.0, 2.0) == TRUE);
    assert (sameSide (1.0, 1.0, 0,   1.0, 2.0, 1.0) == TRUE);
    assert (sameSide (1.0, 0.0, 0,   0.0, 2.0, 0.0) == TRUE);
    
    assert (sameSide (0.5, 0.0, 0,   0.0, 0.0, 1.0) == FALSE);

//  assert (triangleTest (x0, y0, x1, y1, x2, y2, px, py)); //
    assert (triangleTest (0.0, 0.0, 0.0,  1.0,  1.0, 0.0,  0.25,  0.25) == TRUE);
    assert (triangleTest (0.0, 0.0, 0.0,  1.0,  1.0, 0.0,  2.0,   2.0)  == FALSE);
/*
    Special case where P(x,y) lies on a hozizontal line. Not sure if this 
    should be true or false.
    Test is below for either. I will assume a FALSE result for my program
    assert (tritest (0.0, 0.0, 0.0,  1.0,  1.0, 0.0,  0.5,   0.0)  == TRUE); XXX Special
*/
    assert (triangleTest (0.0, 0.0, 0.0,  1.0,  1.0, 0.0,  0.5,   0.0)  == FALSE); 
    assert (triangleTest (0.0, 0.0, 0.0, -1.0, -1.0, 0.0, -0.25, -0.25) == TRUE);

    printf("Tests Completed Sucessfully.\n"); 
    return EXIT_SUCCESS;
}

int sameSide (double px, double py, double gradient, double yIntercept, 
               double lx, double ly){ 
    // two points lie on the same side of a line
    int x;
    int pPosition, lPosition;
    
    pPosition = vertPosition (px, py, gradient, yIntercept);
    lPosition = vertPosition (lx, ly, gradient, yIntercept);
    x = (pPosition == lPosition);
    
    return x;
}

int vertPosition (double px, double py, double gradient, double yIntercept){

    double pointOnLine;
    int location;

    pointOnLine = gradient * px + yIntercept;

    if (py < pointOnLine){
        location = UNDER; // point is under line
    } 
    if (py == pointOnLine){
        location = ON_LINE; //point is on line.
    }
    if (py > pointOnLine){
        location = ABOVE; // point is over line. 
    }

    return location;
}

double gradient (double y1, double y0, double x1, double x0){
    double m;     
    m = (y1-y0)/(x1-x0);
    return m;
}

double intercept (double gradient, double x, double y){
    double c;     
    c = gradient * -x + y;
    return c;
}

int vertLineCheck (double x0, double x1, double x2, double y2, double px, 
                   double py, double m, double b){

    int result;

    if (x1 == x0) { 
        result = ((px <= x0) == (x2 <= x0));
    } else {
        result = sameSide (px, py, m, b, x2, y2);
    }

    return result;
}

int triangleTest (double x0, double y0, double x1, double y1, double x2, 
                  double y2, double px, double py){

    int line1, line2, line3;
    double m01, m02, m12;
    double b01, b02, b12;
    
    // line eqns
    // b: y - y1 = m( x - x1 ), x = 0
    m01 = gradient (y1, y0, x1, x0);
    m02 = gradient (y2, y0, x2, x0);
    m12 = gradient (y2, y1, x2, x1);
    
    b01 = intercept (m01, x1, y1);
    b02 = intercept (m02, x2, y2);
    b12 = intercept (m12, x2, y2);

    // vertical line checks
    line1 = vertLineCheck (x0, x1, x2, y2, px, py, m01, b01);
    line2 = vertLineCheck (x2, x1, x0, y0, px, py, m12, b12);
    line3 = vertLineCheck (x0, x2, x1, y1, px, py, m02, b02);
    
    return line1 && line2 && line3;
}

