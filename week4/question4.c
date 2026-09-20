#include <stdio.h>

int main()
{
    FILE *fp;
    char data[100];

    fp = fopen("data.txt", "a");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    printf("Enter data to append: ");
    scanf(" %[^\n]", data);

    fprintf(fp, "%s\n", data);

    fclose(fp);

    printf("Data appended successfully.\n");

    return 0;
}
