/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main() {
    int R, C, K;
    char a[10][10];

    scanf("%d %d", &R, &C);

    for (int i = 0; i < R; i++) {
        scanf("%s", a[i]);
    }

    scanf("%d", &K);

    K %= 360;

    // 0 องศา
    if (K == 0) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++)
                printf("%c", a[i][j]);
            printf("\n");
        }
    }

    // 90 องศา
    else if (K == 90) {
        for (int j = 0; j < C; j++) {
            for (int i = R - 1; i >= 0; i--)
                printf("%c", a[i][j]);
            printf("\n");
        }
    }

    // 180 องศา
    else if (K == 180) {
        for (int i = R - 1; i >= 0; i--) {
            for (int j = C - 1; j >= 0; j--)
                printf("%c", a[i][j]);
            printf("\n");
        }
    }

    // 270 องศา
    else if (K == 270) {
        for (int j = C - 1; j >= 0; j--) {
            for (int i = 0; i < R; i++)
                printf("%c", a[i][j]);
            printf("\n");
        }
    }

    // 45, 135, 225, 315 องศา
    else {
        /*
            ใช้แนวคิดเส้นทแยงมุม

            45°:
            ตัวอักษรตำแหน่ง (i,j)
            จะอยู่ในแถว i+j
            และตำแหน่ง j-i

            จากนั้นเลื่อนตำแหน่งให้ไม่มีช่องว่าง
            ด้านซ้ายเกินความจำเป็น
        */

        if (K == 45) {
            for (int s = 0; s <= R + C - 2; s++) {

                int min = C;
                int max = -1;

                for (int i = 0; i < R; i++) {
                    int j = s - i;

                    if (j >= 0 && j < C) {
                        if (j - i < min) min = j - i;
                        if (j - i > max) max = j - i;
                    }
                }

                for (int p = min; p <= max; p++) {
                    int found = 0;

                    for (int i = 0; i < R; i++) {
                        int j = s - i;

                        if (j >= 0 && j < C && j - i == p) {
                            printf("%c", a[i][j]);
                            found = 1;
                            break;
                        }
                    }

                    if (!found)
                        printf(" ");
                }

                printf("\n");
            }
        }

        /*
            กรณี 315° สามารถหมุนตารางกลับทิศ
            โดยใช้การสะท้อนตำแหน่งก่อน
        */
        else if (K == 315) {
            for (int s = 0; s <= R + C - 2; s++) {

                int first = -1, last = -1;

                for (int i = 0; i < R; i++) {
                    int j = C - 1 - (s - i);

                    if (j >= 0 && j < C) {
                        if (first == -1)
                            first = i;
                        last = i;
                    }
                }

                for (int i = first; i <= last; i++) {
                    int j = C - 1 - (s - i);

                    if (j >= 0 && j < C)
                        printf("%c", a[i][j]);
                }

                printf("\n");
            }
        }

        /*
            135° และ 225°
            ใช้การหมุนตาราง 180° ก่อน
            แล้วจึงใช้หลัก 315° / 45°
        */
        else {
            char b[10][10];

            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    b[i][j] = a[R - 1 - i][C - 1 - j];

            if (K == 135) {
                for (int s = 0; s <= R + C - 2; s++) {
                    int first = -1, last = -1;

                    for (int i = 0; i < R; i++) {
                        int j = s - i;

                        if (j >= 0 && j < C) {
                            if (first == -1) first = i;
                            last = i;
                        }
                    }

                    for (int i = first; i <= last; i++) {
                        int j = s - i;
                        printf("%c", b[i][j]);
                    }

                    printf("\n");
                }
            }
            else { // 225°
                for (int s = 0; s <= R + C - 2; s++) {
                    int first = -1, last = -1;

                    for (int i = 0; i < R; i++) {
                        int j = C - 1 - (s - i);

                        if (j >= 0 && j < C) {
                            if (first == -1) first = i;
                            last = i;
                        }
                    }

                    for (int i = first; i <= last; i++) {
                        int j = C - 1 - (s - i);
                        printf("%c", b[i][j]);
                    }

                    printf("\n");
                }
            }
        }
    }

    return 0;
}