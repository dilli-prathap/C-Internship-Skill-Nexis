#include <stdio.h>

int main() {
    int a[5], i, positive = 0, negative = 0;

    printf("Enter 5 numbers: ");
    for(i = 0; i < 5; i++) {
        scanf("%d", &a[i]);

        if(a[i] > 0)
            positive++;
        else if(a[i] < 0)
            negative++;
    }

    printf("Positive = %d\n", positive);
    printf("Negative = %d", negative);

    return 0;
}