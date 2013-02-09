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
   int z;
   int y1, x1;
   long total;
   
   //x = 2147483648;
   //maxMin.c:19:4: error: this decimal constant is unsigned only in ISO C90 [-Werror]
   //x = 2147483647;
   //Compiles okay
   //x = -2147483647;
   //Compiles okay
   //x = -2147483648;
   //maxMin.c:25:4: error: this decimal constant is unsigned only in ISO C90 [-Werror]
   y = 2147483647;
   y1 = 1;
   x = 0;
   x1 = -1;
   z = -2147483647;
 
   total = add (x, y);
 
   printf("the sum of %d and %d is %ld\n", x, y, total);
   printf("int: y = %i(%x), size = %d, and is located at %p\n", y, y, sizeof(y), &y);
   printf("int: y1 = %i(%x), size = %d, and is located at %p\n", y1, y1, sizeof(y1), &y1);
   printf("int: x = %i(%x), size = %d, and is located at %p\n", x, x, sizeof(x), &x);
   printf("int: x1 = %i(%x), size = %d, and is located at %p\n", x1, x1, sizeof(x1), &x1);
   printf("int: z = %i(%x), size = %d, and is located at %p\n", z, z, sizeof(z), &z);
   printf("long: total = %ld(%lx), size = %d, and is located at %p\n", total, total, sizeof(total), &total);
    
   //char c = -129;
   //maxMin.c:37:4: error: overflow in implicit constant conversion [-Werror=overflow]
   //char c = 128;
   //Compiles OK
   //char c = 129;
   //comiles okay
   //char c = -128;
   //comiles okay
   //char c = 255;
   //compiles okay
   //char c = 256;
   //maxMin.c:47:4: error: overflow in implicit constant conversion [-Werror=overflow]
   char c = 'a';
   printf("char: c = %c(%x), size = %d, and is located at %p\n", c, c, sizeof(c), &c);

   unsigned long ul       = -1;
   //maxMin.c:52:4: error: large integer implicitly truncated to unsigned type [-Werror=overflow]
   //unsigned long ul       = 2147483647;
   // compiles okay
   //unsigned long ul       = 2147483648;
   //maxMin.c:56:4: error: this decimal constant is unsigned only in ISO C90 [-Werror]
   //unsigned long ul       = -1;   
   //compiles okay
   //unsigned long ul       = -2147483647;
   //compiles okay
   //unsigned long ul       = -2147483648;   
   //maxMin.c:62:4: error: this decimal constant is unsigned only in ISO C90 [-Werror]
   ////unsigned long ul       = 1;
   //unsigned long ul       = 4294967296;
   //unsigned long ul       = 2147483647;
   //unsigned long ul       = 2147483648;
   //unsigned long ul       = -1;   
   //unsigned long ul       = -2147483647;
   //unsigned long ul       = -2147483648;   
   unsigned int ui        = -1;
   //unsigned long ul       = 4294967296;
   //unsigned long ul       = 2147483647;
   //unsigned long ul       = 2147483648;
   //unsigned long ul       = -1;   
   //unsigned long ul       = -2147483647;
   //unsigned long ul       = -2147483648; 
   unsigned long long ull = -1;
   //unsigned long ul       = 4294967296;
   //unsigned long ul       = 2147483647;
   //unsigned long ul       = 2147483648;
   //unsigned long ul       = -1;   
   //unsigned long ul       = -2147483647;
   //unsigned long ul       = -2147483648; 
   unsigned short us      = -1;
 
   printf("unsigned long: ul = %lu(%lx), size = %d, and is located at %p\n", ul, ul, sizeof(ul), &ul);
   printf("unsigned int: ui = %u(%x), size = %d, and is located at %p\n", ui, ui, sizeof(ui), &ui);
   printf("unsigned long long: ull = %llu(%llx), size = %d, and is located at %p\n", ull, ull, sizeof(ull), &ull);
   printf("unsigned short: us = %u(%x), size = %d, and is located at %p\n", us, us, sizeof(us), &us);

   //unsigned long ul       = 4294967296;
   //unsigned long ul       = 2147483647;
   //unsigned long ul       = 2147483648;
   //unsigned long ul       = -1;   
   //unsigned long ul       = -2147483647;
   //unsigned long ul       = -2147483648; 
   signed long sl       = -2147483646;
   //unsigned long ul       = 4294967296;
   //unsigned long ul       = 2147483647;
   //unsigned long ul       = 2147483648;
   //unsigned long ul       = -1;   
   //unsigned long ul       = -2147483647;
   //unsigned long ul       = -2147483648; 
   signed int si        = -2147483647;
   signed long long sll = -9223372036854775807;
   signed short ss      = -32768;
 
   printf("signed long: sl = %ld(%lx), size = %d, and is located at %p\n", sl, sl, sizeof(sl), &sl);
   printf("signed int: si = %d(%x), size = %d, and is located at %p\n", si, si, sizeof(si), &si);
   printf("signed long long: sll = %lld(%llx), size = %d, and is located at %p\n", sll, sll, sizeof(sll), &sll);
   printf("signed short: ss = %d(%x), size = %d, and is located at %p\n", ss, ss, sizeof(ss), &ss);
   
   long l       = 8;
   int i        = 9;
   long long ll = 10;
   short s      = 11;
 
   printf("long: l = %ld(%lx), size = %d, and is located at %p\n", l, l, sizeof(l), &l);
   printf("int: i = %d(%x), size = %d, and is located at %p\n", i, i, sizeof(i), &i);
   printf("long long: ll = %lld(%llx), size = %d, and is located at %p\n", ll, ll, sizeof(ll), &ll);
   printf("short: s = %d(%x), size = %d, and is located at %p\n", s, s, sizeof(s), &s);
   
   float f = 3.1;
   double d = 3.14;
 
   printf("float: f = %f, size = %d, and is located at %p\n", f, sizeof(f), &f);
   printf("double: d =  %f, size = %d, and is located at %p\n", d, sizeof(d), &d);
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
