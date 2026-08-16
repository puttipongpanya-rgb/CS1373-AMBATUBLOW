/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

#define STATES 256
#define NEG -1000000000

int dp[STATES];
int next_dp[STATES];


int get_id(char c)
{
    if (c == 'M') return 1;
    if (c == 'F') return 2;
    return 3; /* B */
}


int score(int a, int b, int c)
{
    int used[4] = {0, 0, 0, 0};
    int result = 0;

    if (a != 0 && !used[a]) {
        used[a] = 1;
        result++;
    }

    if (b != 0 && !used[b]) {
        used[b] = 1;
        result++;
    }

    if (c != 0 && !used[c]) {
        used[c] = 1;
        result++;
    }

    return result;
}


int encode(int a, int b, int c, int d)
{
    return ((a * 4 + b) * 4 + c) * 4 + d;
}


void decode(int state, int *a, int *b, int *c, int *d)
{
    *d = state % 4;
    state /= 4;

    *c = state % 4;
    state /= 4;

    *b = state % 4;
    state /= 4;

    *a = state % 4;
}

int main()
{
    int N;
    char s[100005];

    scanf("%d", &N);
    scanf("%s", s);

 
    for (int i = 0; i < STATES; i++)
        dp[i] = NEG;

    dp[encode(0, 0, 0, 0)] = 0;

    for (int pos = 0; pos < N; pos++) {

        int t = get_id(s[pos]);

        for (int i = 0; i < STATES; i++)
            next_dp[i] = NEG;

        for (int state = 0; state < STATES; state++) {

            if (dp[state] == NEG)
                continue;

            int a, b, c, d;
            decode(state, &a, &b, &c, &d);

   
            {
                int new_a = b;
                int new_b = t;

                int new_state =
                    encode(new_a, new_b, c, d);

                int value =
                    dp[state] + score(a, b, t);

                if (value > next_dp[new_state])
                    next_dp[new_state] = value;
            }

    
            {
                int new_c = d;
                int new_d = t;

                int new_state =
                    encode(a, b, new_c, new_d);

                int value =
                    dp[state] + score(c, d, t);

                if (value > next_dp[new_state])
                    next_dp[new_state] = value;
            }
        }

   
        for (int i = 0; i < STATES; i++)
            dp[i] = next_dp[i];
    }


    int answer = 0;

    for (int state = 0; state < STATES; state++) {
        if (dp[state] > answer)
            answer = dp[state];
    }

    printf("%d\n", answer);

    return 0;
}