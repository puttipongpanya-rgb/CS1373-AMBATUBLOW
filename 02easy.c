/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main() {
    int n, i;
    int num, min, max;

    scanf("%d", &n);

    scanf("%d", &num);
    min = num;
    max = num;

    for (i = 1; i < n; i++) {
        scanf("%d", &num);

        if (num < min)
            min = num;

        if (num > max)
            max = num;
    }

    printf("%d\n", min);
    printf("%d\n", max);

    return 0;
}