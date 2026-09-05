#include <stdio.h>

int main()
{
    int a, b, sum;

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    sum = a + b;

    printf("Sum = %d", sum);

    return 0;
}

/*
OUTPUT:
Enter first number: 10
Enter second number: 20
Sum = 30
*/