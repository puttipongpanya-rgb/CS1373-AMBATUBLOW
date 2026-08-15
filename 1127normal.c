/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int money;
    int cost[10];
    int minCost;
    int length;
    int i, j;

    scanf("%d", &money);

   
    for (i = 1; i <= 9; i++)
    {
        scanf("%d", &cost[i]);
    }

    
    minCost = cost[1];

    for (i = 2; i <= 9; i++)
    {
        if (cost[i] < minCost)
        {
            minCost = cost[i];
        }
    }

   
    length = money / minCost;

  
    for (i = 0; i < length; i++)
    {
        for (j = 9; j >= 1; j--)
        {
          
            if (money - cost[j] >= (length - i - 1) * minCost)
            {
                printf("%d", j);
                money = money - cost[j];
                break;
            }
        }
    }

    printf("\n");

    return 0;
}