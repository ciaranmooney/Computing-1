// Ciarán Mooney
// 9/2/2013 (British Format)
// Downloaded from OpenLearning.com, improved by me.

////////////////////////////////////////////////////////////////////////
// ASCII-BROT :: Student Exercise
/*
  TASK ONE:   Implement the incomplete functions:
 
              - int mandelbrot(double x, double y);
              - void square(point * p);
              - double lengthSquared(point * p);
 
  TASK TWO:   Allow the user to specify a different centre point:
 
              - Currently the centre point is always (0,0).
      - By modifying the range values for X/Y axis, you can
                set the centre point to be any 2D point you like.
 
  CHALLENGE:  Provide a way for the user to specify a 'zoom' level for
              rendering the mandelbrot set.
 
      - In order to implement zoom you will have to replace
        the calculation for scaling the provided x/y values.
      - The zoom level is the number of complex plane units
                between each coordinate represented by a character
                in the Ascii-Brot.
      - For example, initially we have a height of 30 characters,
                with a Y-Axis range of (1 - -1) == 2. This means that
                there are 30/2 units between each coordinate represented
by a character in the Ascii-Brot.
 
For this example if we replaced the axis ranges with zoom,
then a zoom level of 30/2 would give us the same mandelbrot.
*/
////////////////////////////////////////////////////////////////////////
 
// std headers
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
 
// logic defines
#define TRUE   1
#define FALSE  0
 
// ascii-brot size
#define HEIGHT 30
#define WIDTH  72
#define MAX_ITERATIONS 255
 
// ascii-brot viewport
#define MIN_X -1.5
#define MAX_X  1
#define MIN_Y -1
#define MAX_Y  1
#define X_RANGE (MAX_X - MIN_X)
#define Y_RANGE (MAX_Y - MIN_Y)

// *** STUDENT REQUIRED TO COMPLETE THESE FUNCTIONS *** //
int mandelbrot(double x, double y);
double squareX(double x);
double squareY(double y);
double length(double x, double y);
void tests(); 
 
////////////////////////////////////////////////////////////////////////
// complete the mandelbrot algorithm to render a beautiful ASCII-BROT!
 
int main(int argc, char * argv[]) {
  //tests();
  printf(" UNSW Computing 1 - ASCII-BROT\n");
 
  // iterate through each row
  int x = 0;
  int y = 0;
 
  while (y < HEIGHT) {
    // iterate through each column
    while (x < WIDTH) {
    //printf("x=%d, y=%d\n", x, y); 
      if (mandelbrot(x, y)) {
        printf("*");
      } else {
        printf(" ");
      }
      x++;
    }
    printf("\n");
    x = 0;
    y++;
  }
 
  return EXIT_SUCCESS;
}
 
////////////////////////////////////////////////////////////////////////
// Tests all functions, if I can be bothered
// 

void tests(){
    printf("Running SquareX tests.\n");
    assert(squareX(2.0)    == 4.0);
    assert(squareX(-2.0)   == 4.0);
    assert(squareX(1.0)    == 1.0);
    assert(squareX(-1.0)   == 1.0);
    assert(squareX(0.5)  == 0.25);
    assert(squareX(-0.5) == 0.25);
    assert(squareX(0.0) == 0.0);
    printf("SquareX tests passed.\n");
    
    printf("Running SquareY tests.\n");
    assert(squareY(1.0)    == -1.0); //i^2 imaginary numbers
    assert(squareY(-1.0)   == -1.0);  //-i^2
    assert(squareY(2.0)    == -4.0); //2i**2
    assert(squareY(-2.0)   == -4.0);  //-2i**2
    assert(squareY(-0.5)   == -0.25);  //
    assert(squareY(0.5)    == -0.25);  //
    assert(squareY(0.0)    == 0.0);  //
    printf("SquareY tests passed.\n");
    
    printf("Running lengthSquared tests.\n");
    assert(length(0.0,0.0) == 0.0);
    assert(length(3.0,4.0) == 25.0);
    assert(length(2.0,-3.0) == 13.0);
    assert(length(1.0,1.0) == 2.0);
    printf("lengthSquared tests passed.\n");
    
    printf("Running manbrot tests.\n");
    assert(mandelbrot(1,1) == FALSE);
    printf("Manbrot tests passed.\n");
    
    
    printf("All tests passed.\n");

}
 
////////////////////////////////////////////////////////////////////////
// implement mandelbrot escape-time algorithm for a given x,y coordinate
// (whether or not a point is in the mandelbrot set or not)
 
int mandelbrot(double x, double y) {
  int result = FALSE;
  double Zx, Zy;
  double Cx, Cy;
  double real, imag;
  double distance;

  int counter;
  counter = 0;
 /*
Step 1: get x as a percentage of the maximum screen x
Step 2: multiply x by the X_RANGE (of the mandelbrot "world" coordinates)
Step 3: add the MIN_X (of the Mandelbrot range) to the value you got in step 2
 */

  Cx = ((x/HEIGHT) * X_RANGE) + MIN_X;
  Cy = ((y/WIDTH) * Y_RANGE) + MIN_Y;
  printf("Cx=%f, Cy=%f\n", Cx, Cy);
  Zx = 0.0;
  Zy = 0.0;

  // Z = Z^2 + C
  // Z^2 = (x + yi)^2 = x^2 + 2xyi + (yi)^2
  // real(Z^2) = x^2 + (yi)^2
  // imaginary = 2xy

  // C = (a + bi)

  // Z = sum(real) + sum(imaginary)
  // Z = real(a + x^2 + (yi)^2) + imaginary (2xyi + bi)

  while (counter < MAX_ITERATIONS && distance < 4.0){
    real = squareX(Zx) + squareY(Zy) + Cx;
    imag = (2.0*Zx*Zy) + Cy;
    Zx = real;
    Zy = imag;
    distance = length(Zx, Zy);
    printf("real = %f, imag = %f, dis = %f, quit=%i\n", Zx, Zy, distance, distance < 4.0);
    counter = counter + 1;
  }

  if (distance < 4.0){
    result = TRUE;
  }
  
  return result;
}
 
////////////////////////////////////////////////////////////////////////
// compute the length/magnitude (squared) of a 2D vector
// in other words the distance squared of a point from the origin.
 
double length(double x, double y) {
  double length;
  double X, Y;

  X = squareX(x);
  Y = squareX(y);
  //printf("X=%f, Y=%f\n", X, Y);
  length = X + Y;
  return length;
}
 
 
////////////////////////////////////////////////////////////////////////
// performs the calculation Z^2 for the real part of a complex number
 
double squareX(double x) {
    double X;
    X = x * x;
    return X; 
}
 
////////////////////////////////////////////////////////////////////////
// performs the calculation Z^2 for the imaginary part of a complex number
 
double squareY(double y) {
    // multiply by magnitude then the sign.
    double Y;
    Y = (y * y) * -1.0;

    return Y;
}
 
// EOF
