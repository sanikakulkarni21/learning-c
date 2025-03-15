#include <stdio.h>
#include <stdlib.h>

void add_numbers() {
    int num1, num2, sum;
    printf("Enter two numbers for addition: ");
    scanf("%d %d", &num1, &num2);
    sum = num1 + num2;
    printf("Sum of numbers: %d\n", sum);
}

void add_binary_numbers() {
    int a, b, result, carry = 0;
    printf("Enter two binary numbers (0s and 1s): \n");
    printf("Enter first binary number: ");
    scanf("%d", &a);
    printf("Enter second binary number: ");
    scanf("%d", &b);

    // Perform binary addition
    result = (a ^ b) ^ carry;
    carry = (a & b) | (carry & (a ^ b));

    printf("Binary sum: %d\n", result);
}

void add_characters() {
    char ch1, ch2;
    int sum;
    printf("Enter two characters: ");
    scanf(" %c %c", &ch1, &ch2);  // Add a space before %c to handle previous input correctly.
    sum = ch1 + ch2;
    printf("Sum of character values (ASCII): %d\n", sum);
}

int main() {
    int choice;

    printf("Choose an operation:\n");
    printf("1. Addition of two numbers\n");
    printf("2. Addition of two binary numbers\n");
    printf("3. Addition two characters\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            add_numbers();
            break;
        case 2:
            add_binary_numbers();
            break;
        case 3:
            add_characters();
            break;
        default:
            printf("Invalid choice please enter valid choice!\n");
            break;
    }

    return 0;
}