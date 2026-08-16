/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main(void)
{
    int N, M;
    char S[1000005];

    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%s", S);

 
    long long X = 0;
    long long Y = 0;
    long long Z = 0;

    int u = 0;
    int d = 0;

    for (int i = 0; i < N; i++) {

        long long oldX = X;

   
        X = (2 * Y + Z) % M;
        Y = oldX;

    
        if (S[i] == 'P' && u != 2) {

            if (u == 1) {

                X++;

            }
            else if (d == -2) {

                Y++;

            }
            else {

                Z++;
            }

      
            if (X >= M)
                X -= M;

            if (Y >= M)
                Y -= M;

            if (Z >= M)
                Z -= M;
        }

     
        if (S[i] == 'L') {

       
            u = u + 1;

            if (u < 1)
                u = 1;

            d = d + 1;

        }
        else {

      
            u = u - 1;

            d = d - 1;

            if (d > -1)
                d = -1;
        }

     
        X %= M;
        Y %= M;
        Z %= M;
    }

  
    printf("%lld\n", (X + Y + Z + 1) % M);

    return 0;
}