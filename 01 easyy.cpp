/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>


    int main() {
    int num1;
    int num2;
    int num3;
    int grade;
    
    scanf("%d", &num1);

    scanf("%d", &num2);

    scanf("%d", &num3);
    
    grade = num1 + num2 + num3;
    
    if(grade <=49){
        printf("F\n");
    }else if(grade <=54){
    printf("D\n");
    }else if(grade <=59){
    printf("D+\n");
    }else if(grade <=64){
    printf("C\n");
    }else if(grade <=69){
    printf("C+\n");
    }else if(grade <=74){
    printf("B\n");
    }else if(grade <=79){
    printf("B+\n");
    }else if(grade <=100){
    printf("A\n");
}
   
    
    
    

    return 0;
}