/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

typedef long long ll;


ll counting(ll x, ll y)
{
    ll type[64];
    ll res = 1;
    ll cnt = 0;
    ll i;


    for (; y; res <<= 1, y >>= 1) {
        if (y & 1)
            type[++cnt] = res;
    }

    res = 0;

 
    for (i = cnt; i > 0; --i) {
        if (x - type[i] >= 0) {
            x -= type[i];

  
            res |= (1LL << (i - 1));
        }
    }


    return res + 1;
}

int main()
{
    ll n, m, k;

    scanf("%lld %lld", &n, &m);
    scanf("%lld", &k);


    int direction = 1;

    if (m < n) {
        ll tmp = n;
        n = m;
        m = tmp;

        direction = 0;
    }

    ll ans = 0;
    ll done = 0;

 
    for (ll i = 0; i < m; ++i, direction ^= 1) {

        ll cnt = (i + 1 < n ? i + 1 : n);

  
        if (done + cnt < k) {

            done += cnt;

            ans += counting(
                (i < n - 1 ? i : n - 1),
                i
            );
        }
        else {

       
            if (direction) {

                ll p = (i < n - 1 ? i : n - 1);
                ll q = i - (i < n - 1 ? i : n - 1);

                while (done < k) {

                    if (p + q == (p ^ q))
                        ++ans;

                    --p;
                    ++q;
                    ++done;
                }

            }
            else {

                ll p = 0;
                ll q = i;

                while (done < k) {

                    if (p + q == (p ^ q))
                        ++ans;

                    ++p;
                    --q;
                    ++done;
                }
            }

            break;
        }
    }

 
    if (done == k) {
        printf("%lld\n", ans);
        return 0;
    }

 
    for (ll i = 1; i < n; ++i, direction ^= 1) {

        ll cnt = n - i;

    
        if (done + cnt < k) {

            done += cnt;

        
            ans +=
                counting(n - 1, m + i - 1)
                - counting(i - 1, m + i - 1);
        }
        else {

       
            if (direction) {

                ll p = n - 1;
                ll q = m - n + i;

                while (done < k) {

                    if (p + q == (p ^ q))
                        ++ans;

                    --p;
                    ++q;
                    ++done;
                }

            }
            else {

                ll p = i;
                ll q = m - 1;

                while (done < k) {

                    if (p + q == (p ^ q))
                        ++ans;

                    ++p;
                    --q;
                    ++done;
                }
            }

            break;
        }
    }

    printf("%lld\n", ans);

    return 0;
}