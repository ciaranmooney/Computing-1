//
//  main.c
//  memory
//
//  Created by Richard Buckland on 20/11/12.
//
 
#include <stdio.h>
#include <stdlib.h>
 
long add (int x, int y);
 
int main(int argc, const char * argv[]) {
 
   int x;
   int y;
   long total;
   
   x = 40;
   y = 2;
 
   total = add (x, y);
 
   printf("the sum of %d and %d is %ld\n", x, y, total);
   printf("the size of %d is %d, and is located at %p\n", x, sizeof(x), &x);
   printf("the size of %d is %d, and is located at %p\n", y, sizeof(y), &y);
   printf("the size of %ld is %d, and is located at %p\n", total, sizeof(total), &total);
    
   char c ='a';
 
   printf("the size of a is %d, and is located at %p\n", sizeof(c), &c);

   unsigned long ul       = 0;
   unsigned int ui        = 1;
   unsigned long long ull = 2;
   unsigned short us      = 3;
 
   printf("the size of %ld is %d, and is located at %p\n", ul, sizeof(ul), &ul);
   printf("the size of %d is %d, and is located at %p\n", ui, sizeof(ui), &ui);
   printf("the size of %lld is %d, and is located at %p\n", ull, sizeof(ull), &ull);
   printf("the size of %d is %d, and is located at %p\n", us, sizeof(us), &us);

   signed long sl       = 4;
   signed int si        = 5;
   signed long long sll = 6;
   signed short ss      = 7;
 
   printf("the size of %ld is %d, and is located at %p\n", sl, sizeof(sl), &sl);
   printf("the size of %d is %d, and is located at %p\n", si, sizeof(si), &si);
   printf("the size of %lld is %d, and is located at %p\n", sll, sizeof(sll), &sll);
   printf("the size of %d is %d, and is located at %p\n", ss, sizeof(ss), &ss);
   
   long l       = 8;
   int i        = 9;
   long long ll = 10;
   short s      = 11;
 
   printf("the size of %ld is %d, and is located at %p\n", l, sizeof(l), &l);
   printf("the size of %d is %d, and is located at %p\n", i, sizeof(i), &i);
   printf("the size of %lld is %d, and is located at %p\n", ll, sizeof(ll), &ll);
   printf("the size of %d is %d, and is located at %p\n", s, sizeof(s), &s);
   
   float f = 3.1;
   double d = 3.14;
 
   printf("the size of %f is %d, and is located at %p\n", f, sizeof(f), &f);
   printf("the size of %f is %d, and is located at %p\n", d, sizeof(d), &d);
   // add them all together just to make use of them so the compiler
   // doesn't grumble that they are unused in the program
 
   double grandTotal;
   grandTotal =  c +
				 ul + ui + ull + us +
				 sl + si + sll + ss +
				  l +  i +  ll +  s +
				  f + d;
 
   printf ("all these things added together make %f\n", grandTotal);
 
   return EXIT_SUCCESS;
}
 
long add (int x, int y) {
   long answer;
   answer = x + y;
 
   return answer;
}
