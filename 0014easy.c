/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main() {
    long long a, b, temp;

    scanf("%lld %lld", &a, &b);

    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }

    printf("%lld", a);

    return 0;
}