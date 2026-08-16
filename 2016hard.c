/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

#define LIM 4000000000000000000LL

int id(char c) {
    if (c == 'A') return 0;
    if (c == 'C') return 1;
    if (c == 'G') return 2;
    return 3;   /* T */
}

char letter(int x) {
    const char s[] = "ACGT";
    return s[x];
}

int main() {
    int M, K;
    ll R;
    char *s;
    ll *dp;

    scanf("%d %d %lld", &M, &K, &R);

    s = (char *)malloc((M + 1) * sizeof(char));
    scanf("%s", s);

 
    int STATES = (K + 1) * 4;

    dp = (ll *)calloc((long long)(M + 1) * STATES, sizeof(ll));

    #define DP(i,d,last) dp[(long long)(i) * STATES + (d) * 4 + (last)]


    for (int d = 0; d <= K - 1; d++) {
        for (int last = 0; last < 4; last++) {
            DP(M, d, last) = 1;
        }
    }


    for (int i = M - 1; i >= 1; i--) {
        for (int d = 0; d <= K - 1; d++) {
            for (int last = 0; last < 4; last++) {

                ll ways = 0;

                for (int x = 0; x < 4; x++) {

             
                    if (s[i] != 'N' && id(s[i]) != x)
                        continue;

                    if (x < last) {
                 
                        if (d == 0)
                            continue;

                        ways += DP(i + 1, d - 1, x);
                    } else {
                        ways += DP(i + 1, d, x);
                    }

                 
                    if (ways > LIM)
                        ways = LIM;
                }

                DP(i, d, last) = ways;
            }
        }
    }


    ll remaining = R;

    int prev = -1;
    int dleft = K - 1;

    for (int i = 0; i < M; i++) {

        for (int x = 0; x < 4; x++) {

    
            if (s[i] != 'N' && id(s[i]) != x)
                continue;

            int nd = dleft;

    
            if (prev != -1 && x < prev) {
                if (dleft == 0)
                    continue;

                nd--;
            }

            ll cnt;

            if (i == M - 1) {
                cnt = 1;
            } else {
                cnt = DP(i + 1, nd, x);
            }

    
            if (remaining <= cnt) {
                s[i] = letter(x);
                prev = x;
                dleft = nd;
                break;
            } else {
                remaining -= cnt;
            }
        }
    }

    printf("%s\n", s);

    free(dp);
    free(s);

    return 0;
}