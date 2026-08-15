/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int d;
    int iCount = 0;
    int vCount = 0;
    int xCount = 0;
    int lCount = 0;
    int cCount = 0;

    scanf("%d", &d);

    for (int i = 1; i <= d; i++)
    {
        int n = i;

      
        while (n >= 100)
        {
            cCount++;
            n = n - 100;
        }

     
        if (n >= 90)
        {
            xCount++;
            cCount++;
            n = n - 90;
        }

   
        if (n >= 50)
        {
            lCount++;
            n = n - 50;
        }

   
        if (n >= 40)
        {
            xCount++;
            lCount++;
            n = n - 40;
        }

   
        while (n >= 10)
        {
            xCount++;
            n = n - 10;
        }

   
        if (n >= 9)
        {
            iCount++;
            xCount++;
            n = n - 9;
        }

   
        if (n >= 5)
        {
            vCount++;
            n = n - 5;
        }

   
        if (n >= 4)
        {
            iCount++;
            vCount++;
            n = n - 4;
        }

    
        while (n >= 1)
        {
            iCount++;
            n = n - 1;
        }
    }

    printf("%d %d %d %d %d\n",
           iCount, vCount, xCount, lCount, cCount);

    return 0;
}