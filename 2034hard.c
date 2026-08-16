/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define MAXN 50
#define INF 1000000000000000LL

int N, M;
long long a[MAXN][MAXN];
long long prefix[MAXN + 1][MAXN + 1];


long long dp[MAXN][MAXN][MAXN][MAXN];


long long sum(int r1, int c1, int r2, int c2)
{
    return prefix[r2][c2]
         - prefix[r1][c2]
         - prefix[r2][c1]
         + prefix[r1][c1];
}

long long solve(int r1, int c1, int r2, int c2)
{
    long long *ans = &dp[r1][c1][r2 - 1][c2 - 1];


    if (r2 - r1 == 1 && c2 - c1 == 1)
        return 0;

    if (*ans != -1)
        return *ans;

    *ans = INF;


    for (int r = r1 + 1; r < r2; r++) {

        long long top = solve(r1, c1, r, c2);
        long long bottom = solve(r, c1, r2, c2);

        long long value = top + bottom;

        if (value < *ans)
            *ans = value;
    }


    for (int c = c1 + 1; c < c2; c++) {

        long long left = solve(r1, c1, r2, c);
        long long right = solve(r1, c, r2, c2);

        long long value = left + right;

        if (value < *ans)
            *ans = value;
    }


    *ans += sum(r1, c1, r2, c2);

    return *ans;
}

int main()
{
    scanf("%d %d", &N, &M);


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%lld", &a[i][j]);
        }
    }


    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {

            prefix[i][j] =
                a[i - 1][j - 1]
                + prefix[i - 1][j]
                + prefix[i][j - 1]
                - prefix[i - 1][j - 1];
        }
    }


    for (int r1 = 0; r1 < N; r1++) {
        for (int c1 = 0; c1 < M; c1++) {
            for (int r2 = 0; r2 < N; r2++) {
                for (int c2 = 0; c2 < M; c2++) {
                    dp[r1][c1][r2][c2] = -1;
                }
            }
        }
    }

    printf("%lld\n", solve(0, 0, N, M));

    return 0;
}