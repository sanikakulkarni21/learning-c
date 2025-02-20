#include <stdio.h>


//using recursion
int factorialUsingRecursion(int n){
    if(n ==0) 
    return 1;                         //Base case
    return n * factorialUsingRecursion(n-1);    //Recursive case
}

int main(){
    printf("Recursion \n");
    printf("\n Enter the number ");
    int number;
    scanf( "%d", &number);
    //int finalResult= factorial(number);
    int finalResult= factorialUsingRecursion(number);
    printf("Factorial of %d = %d", number, finalResult);
}